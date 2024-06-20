#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funciones:

/// Inicializa las manzanas en el tablero.
/// Llamada al iniciar el programa y luego de los eventos.
/// manzana tiene 4 elementos de 2 elementos cada una: fila y columna.
/// serpiente tiene 3 elementos de 2 elementos cada una: fila y columna.
void setear_tablero(int tamanio, char manzanas[][2], char serpiente[][2], char tablero[][6], bool serpiente_definida){

    srand (time(NULL));

    int fila, columna;

    // Todas las celdas con espacios
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            tablero[i][j] = ' ';
        }
    }


    // serpiente[0] tiene la celda de la cabeza
    // serpiente[1] y [2] tienen el cuerpo
    // si viene de eventos la serpiente ya esta definida
    if (!serpiente_definida){

        for (int i = 1; i < 4; i++) {

            /*
            // Esa celda tiene un espacio, me sirve para la serpiente
            // Pero no la voy a guardar asi puedo imprimir en normal
            if (i==1) tablero[fila][columna] = '#';
            else tablero[fila][columna] = '*';
            */

            // si i=1 es la cabeza
            if (i==1) {
                // guardo la cabeza en cualquier casilla que este libre
                do {
                    // genero una celda random para la serpiente
                    fila = rand() % 3;//0 1 2
                    fila = fila + 4;//4 5 6
                    columna = rand() % 5;
                    columna++;
                }while(!tablero[fila][columna]==' ');

                serpiente[1][0] = fila;
                serpiente[1][1] = columna;

                // temporal. borrar!!
                tablero[fila][columna] = '#';
            } else {
                // no es la cabeza. agrego en fila para abajo, sino cambio columna


                if (fila>1)fila--;

                // temporal. borrar!! Esta mal! Setear serpiente.
                if (tablero[fila][columna]==' ') {
                    serpiente[i][0] = fila;
                    serpiente[i][1] = columna;
                    tablero[fila][columna] = '*';
                }
            }
        }

        serpiente_definida = true;

        printf("Tablero con serpiente definida\n");
        printf("   1 2 3 4 5 6\n");
        for (int i = 1; i < 7; i++) {
            printf("%d |", i);
            for (int j = 1; j < 7; j++) {
                printf("%c|", tablero[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    } else {

        // Sumo la serpiente
        for (int i = 1; i < 4; i++) {
            fila = serpiente[i][0];
            columna = serpiente[i][1];
            if (i==1) tablero[fila][columna] = '#';
            else tablero[fila][columna] = '*';
        }

    }


    // Ahora sumo unas nuevas manzanas
    for (int i = 1; i < 5; i++) {
        do {
            // genero una celda random para la manzana
            fila = rand() % 5;
            fila++;
            columna = rand() % 5;
            columna++;
        }while(tablero[fila][columna]!=' ');

        //printf("Celda tablero: |%c|\n", tablero[fila][columna]);
        //printf("Manzana: Fila: %d - Columna: %d\n", fila, columna);


        // Esa celda tiene un espacio, guardo la manzana
        tablero[fila][columna] = 'o';


        // guardo las manzanas para comparar mas rapido despues
        manzanas[i][0] = fila;
        manzanas[i][1] = columna;
    }


};


/// Imprime el tablero normal
void imprimir_tablero_normal(int tamanio, char manzanas[][2], char tablero[][6]){

    srand (time(NULL));

    int fila, columna;


    // Todas las celdas con espacios
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            tablero[i][j] = ' ';
        }
    }

    // Inserto las manzanas
    for (int i = 1; i < 5; i++) {
        fila = manzanas[i][0];
        columna = manzanas[i][1];
        tablero[fila][columna] = 'o';
    }

    printf("Tablero normal\n");
    printf("   1 2 3 4 5 6\n");
    for (int i = 1; i < 7; i++) {
        printf("%d |", i);
        for (int j = 1; j < 7; j++) {
            printf("%c|", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");

};


/// Muevo la serpiente en el tablero
bool mover_serpiente(int tamanio, char serpiente[][2], char tablero[][6]){
    printf("Muevo la serpiente...\n");

    //int fila_cabeza, columna_cabeza, fila_cuerpo, columna_cuerpo, fila_cola, columna_cola;
    int fila_cabeza, columna_cabeza, mov, fila, columna, fila_vieja, columna_vieja;
    bool comio_manzana = false, encontre_celda = false;

    // obtener nuevas filas posibles para mover la cabeza
    // generar opciones random:

    srand (time(NULL));

    // ubico la cabeza:
    fila_cabeza = serpiente[1][0];
    columna_cabeza = serpiente[1][1];

    printf("Fila cabeza: %d - Columna cabeza: %d\n", fila_cabeza, columna_cabeza);


    /*
    // Temporal, borrar! El tablero trae manzanas
    // Tengo que ubicar primero a la serpiente.
    printf("Tablero antes de mover serpiente.\n");
    printf("   1 2 3 4 5 6\n");
    for (int i = 1; i < 7; i++) {
        printf("%d |", i);
        for (int j = 1; j < 7; j++) {
            printf("%c|", tablero[i][j]);
        }
        printf("\n");
    }
    */



    // Sumo la serpiente
    for (int i = 1; i < 4; i++) {
        fila = serpiente[i][0];
        columna = serpiente[i][1];
        if (i==1) tablero[fila][columna] = '#';
        else tablero[fila][columna] = 'c*';
    }

    printf("Tablero antes de mover serpiente.\n");
    printf("   1 2 3 4 5 6\n");
    for (int i = 1; i < 7; i++) {
        printf("%d |", i);
        for (int j = 1; j < 7; j++) {
            printf("%c|", tablero[i][j]);
        }
        printf("\n");
    }


    // Muevo la cebeza 3 lugares
    for (int i = 3; i > 0; i--) {

        fila_vieja = fila_cabeza;
        columna_vieja = columna_cabeza;

        do {

            fila_cabeza = fila_vieja;
            columna_cabeza = columna_vieja;

            mov = rand() % 4;

            switch(mov){
                case 0:
                    //ariba de cabeza
                    if (fila_cabeza > 2) {fila_cabeza--;printf("ARRIBA\n");}
                break;
                case 1:
                    //derecha de cabeza
                    if (columna_cabeza < 6) {columna_cabeza++; printf("DERECHA\n");}
                break;
                case 2:
                    //abajo de cabeza
                    if (fila_cabeza < 6) {fila_cabeza++; printf("ABAJO\n");}
                break;
                case 3:
                    //izquierda de cabeza
                    if (columna_cabeza > 2) {columna_cabeza--; printf("IZQUIERDA\n");}
                break;
            }

            if (tablero[fila_cabeza][columna_cabeza] != '#' && tablero[fila_cabeza][columna_cabeza] != '*' ) {
                encontre_celda = true;
                //fila_nueva = fila_cabeza
                //columna_nueva = columna_cabeza;

                if (tablero[fila_cabeza][columna_cabeza] == 'o'){
                    comio_manzana = true;
                }
            }

        }while (!encontre_celda);

        //hacer chequeos a partir de la celda de la cabeza.
        //serpiente[3][0] queda la cola. luego en el proximo queda el cuerpo y en serpiente[0][0] queda la cabeza.
        //serpiente[i][0] = fila_nueva;
        //serpiente[i][1] = columna_nueva;

        serpiente[i][0] = fila_cabeza;
        serpiente[i][1] = columna_cabeza;


        fila_vieja = fila_cabeza;
        columna_vieja = columna_cabeza;


        printf("Fila cabeza: %d - Columna cabeza: %d\n", fila_cabeza, columna_cabeza);

        // ubico donde estaria avanzando la cabeza:
        //fila_cabeza = fila_cabeza;
        //columna_cabeza = columna_cabeza;


        // volver a insertar la serpiente


        printf("Tablero despues de mover serpiente.\n");
        printf("   1 2 3 4 5 6\n");
        for (int i = 1; i < 7; i++) {
            printf("%d |", i);
            for (int j = 1; j < 7; j++) {
                printf("%c|", tablero[i][j]);
            }
            printf("\n");
        }

    }

    return comio_manzana;

};


/// Indica si la serpiente se encuentra en la celda indicada
/// 1 acerto - 0 no acerto
bool acerto_serpiente(int filaUsuario, int colUsuario, char serpiente[][2]){
    printf("Chequeo si acerto la serpiente...\n");
    return true;
};


/// Indica si la serpiente comio una manzana
/// 1 comio - 0 no comio
bool comio_manzana(char manzanas[][2], char serpiente[][2]){
    printf("Chequeo si comio manzana...\n");
    return false;
};

/*
/// Chequea si hubo algun evento en el turno actual
/// Si acerto, entonces le suma puntos al usuario e imprime el tablero de eventos
void eventos(int tamanio, int acerto=0, int comio=0){
    printf("Chequeo si hubo algun evento...\n");
};
*/

/// Imprime el tablero de eventos
/// Llamado desde eventos para imprimir los 2 turnos especiales de serpiente visible.
/// Deberia luego hacer un llamado a setear manzanas para obtener nuevas manzanas.
/// Luego si va nuevamente a comienzo de bucle imprimir_tablero_normal
void imprimir_tablero_eventos(int tamanio, char manzanas[][2], char serpiente[][2], char tablero[][6]){
    /*
    printf("Tablero de eventos:\n");
    printf("   1 2 3 4 5 6\n");
    printf("1 | | | | | | |\n");
    printf("2 | |C| | | | |\n");
    printf("3 | |c| | | | |\n");
    printf("4 | |c| | | | |\n");
    printf("5 | | | | | | |\n");
    printf("6 | | | | | | |\n");
    */

    //srand (time(NULL));

    int fila, columna;

    // Todas las celdas con espacios
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            tablero[i][j] = ' ';
        }
    }

    // Sumo la serpiente
    for (int i = 1; i < 4; i++) {
        fila = serpiente[i][0];
        columna = serpiente[i][1];
        if (i==1) tablero[fila][columna] = '#';
        else tablero[fila][columna] = '*';
    }


    printf("   1 2 3 4 5 6\n");
    for (int i = 1; i < 7; i++) {
        printf("%d ", i);
        for (int j = 1; j < 7; j++) {
            printf("|%c", tablero[i][j]);
        }
        printf("|\n");
    }

};



///
bool ingresar_celda(int tamanio, int &filaUsuario, char &comaUsuario, int &colUsuario){

    printf("Encuentre a la serpiente, indique la fila y la columna, separadas por coma:\n");
    do {
        scanf("%d", &filaUsuario);
        scanf("%c", &comaUsuario);
        scanf("%d", &colUsuario);

        //datos_validos = validar_datos(tamanio, filaUsuario, comaUsuario, colUsuario);
        if (filaUsuario>1 && filaUsuario<6 && colUsuario>1 && colUsuario<6 && comaUsuario==',') return true;

        //if (!datos_validos) printf("Entrada invalida, vuelva a intentarlo:\n");
        printf("Entrada invalida, vuelva a intentarlo:\n");

    } while (1==1);

    return true;
};



int main()
{
    srand(time(NULL));

    int tamanio=6, cantManzanas=4, puntosUsuario=0, puntosSerpiente=0, filaUsuario=0, colUsuario=0, contador=0;
    char tablero[6][6], serpiente[3][2], manzanas[4][2], caracterComa=',', cabezaSerpiente='176', cuerpoSerpiente='174', comaUsuario, charManzana='180';
    bool acertoSerpiente=false, comioManzana=false, datos_validos=false, serpiente_definida=false;

    printf("Bienvenidos\n\n");

    setear_tablero(tamanio, manzanas, serpiente, tablero, serpiente_definida);

    // bucle principal del juego
    do {

        imprimir_tablero_normal(tamanio, manzanas, tablero);
        ingresar_celda(tamanio, filaUsuario, comaUsuario, colUsuario);// datos validos, puedo mover la serpiente
        comioManzana = mover_serpiente(tamanio, serpiente, tablero);
        acertoSerpiente = acerto_serpiente(filaUsuario, colUsuario, serpiente);
        //comioManzana = comio_manzana(manzanas, serpiente);

        // Chequea si hubo algun evento en este turno
        if (acertoSerpiente || comioManzana){
            if (acertoSerpiente){
                puntosUsuario++;
                printf("Usuario acerto!\n");
            } else{
                puntosSerpiente++;
                printf("Serpiente comio manzana!\n");
            }
            printf("Puntos usuario: %d\nPuntos serpiente: %d\n", puntosUsuario, puntosSerpiente);


            // Para ambos eventos se imprime el mismo tablero de eventos.
            // Durante 3 turnos imprime el tablero con la serpiente visible.
            // En cada uno de estos turnos le vuelve a pedir al usuario que ingrese una celda
            // Luego de ingresar la celda setea unas nuevas manzanas y mueve la serpiente (3 turnos)
            // Le avisa si acerto o no
            // Luego de esos 3 turnos imprime el tablero normal (4 manzanas y no se ve la serpiente).
            // Luego de eso comienza el bucle principal de nuevo, pidiendole que ingrese nueva celda.

            if (puntosUsuario < 3 && puntosSerpiente < 3) {
                for (contador=0; contador < 3; contador++){
                    imprimir_tablero_eventos(tamanio, manzanas, serpiente, tablero);
                    ingresar_celda(tamanio, filaUsuario, comaUsuario, colUsuario);// datos validos, puedo mover la serpiente
                    comioManzana = mover_serpiente(tamanio, serpiente, tablero);
                    acertoSerpiente = acerto_serpiente(filaUsuario, colUsuario, serpiente);
                    //comioManzana = comio_manzana(manzanas, serpiente);

                    if (puntosUsuario < 3 && puntosSerpiente < 3) {
                        if (acertoSerpiente){
                            puntosUsuario++;
                            printf("Usuario acerto!\n");
                        } else{
                            puntosSerpiente++;
                            printf("Serpiente comio manzana!\n");
                        }
                        printf("Puntos usuario: %d\nPuntos serpiente: %d\n", puntosUsuario, puntosSerpiente);
                    }

                }
            }

            setear_tablero(tamanio, manzanas, serpiente, tablero, serpiente_definida);
            //imprimir_tablero_normal(tamanio, manzanas, tablero);
        } else printf("No hubo eventos en este turno, vuelvo a comenzar...\n");


    } while (puntosUsuario < 3 && puntosSerpiente < 3);


    if (puntosUsuario == 3) printf("Lo lograste, has cazado a la serpiente");
    else printf("La serpiente te ha derrotado, suerte la próxima");


    return 0;
}
