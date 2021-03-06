// functions pre-definitions:
int solveMenu();
int mainMenu();
int fileNameInput();


// functions:
int mainMenu() {
    char mainMenuOption;

    printf("                      N-Queens Problem\n");
    printf("----------------------------------------------------------------\n\n");

    do{
        printf("                      Main Menu\n");
        printf("1. Calculate different ways to put N queens in a game board.\n");
        printf("2. show different ways to put N queens in a game board.\n");
        printf("3. export different ways to put N queens in a game board to a \".txt\" file.\n");
        printf("4. show different ways to put N queens in a game board and export results to a file.\n");
        printf("5. EXIT\n");
        printf(" Please enter an option from the main menu: ");

        scanf(" %c", &mainMenuOption);
        switch(mainMenuOption){
            case '1':
                solveMenu();
                break;

            case '2':
                printQueen = 1;
                solveMenu();
                break;

            case'3':
                makeFile = 1;
                if ( fileNameInput() ) solveMenu();
                break;

            case'4':
                printQueen = 1,
                makeFile = 1;
                if ( fileNameInput() ) solveMenu();
                break;

            case'5':
                return 0;
                break;

            default:
                printf("Invalid input!\n");
                break;
        }

    }while(mainMenuOption !='5');

    return 0;
}


int solveMenu() {
    char solveMenuOption;
    int queenN;

    do{
        printf("\n Choose your desired board\n");
        printf("1. Square board\n");
        printf("2. Rectangular board\n");
        printf("3. RETURN\n");
        printf(" Please enter your desired option: ");

        scanf(" %c", &solveMenuOption);
        if (solveMenuOption == '1'){

                printf("\n Please enter the number of queens: ");
                scanf("%d", &queenN);
                puts("");

                printf(" Please enter the size of square's side: ");
                scanf("%d", &maxX);
                maxY = maxX;
                puts("");

                int grid[maxX][maxY];
                for (int i = 0; i < maxX; i++) {
                    for (int j = 0; j < maxY; j++) {
                        grid[i][j] = 0;
                    }
                }

                nQueenSolve(queenN, grid);

                return 0;

        } else if (solveMenuOption == '2') {

                printf("\n Please enter the number of queens: ");
                scanf("%d", &queenN);
                puts("");

                printf(" Please enter the size of rectangle's X side: ");
                scanf("%d", &maxX);
                printf(" Please enter the size of rectangle's Y side: ");
                scanf("%d", &maxY);
                puts("");

                int grid[maxX][maxY];
                for (int i = 0; i < maxX; i++) {
                    for (int j = 0; j < maxY; j++) {
                        grid[i][j] = 0;
                    }
                }

                nQueenSolve(queenN, grid);

                return 0;

        } else if(solveMenuOption == '3') {

                return 0;

        } else {

                printf("Invalid input!\n");

        }

    }while(solveMenuOption !='3');

    return 0;
}

int fileNameInput() {
    FILE *destFilePtr;
    printf(" Please enter your desired path and name for the exported file\nin \"PATH.NAME.txt\" (less than 200 characters):");
    scanf("%s", fileName);
    destFilePtr = fopen(fileName, "a");

    if (destFilePtr == NULL) {
        printf("Unable to open file!\n");
        return 0;
    }

    fclose(destFilePtr);
    return 1;
}




