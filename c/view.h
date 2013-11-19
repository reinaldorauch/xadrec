/**
 * Header para as funções de visualização
 */

#define TAB_WIDTH 8
#define FIELD_SIZE 6

/**
 * Imprime o tabuleiro na window w
 * @param w window que o tabuleiro será exibido
 */
void imprime_tabuleiro(WINDOW *w, TABULEIRO *tab) {

    // Aloca memória para os contadores
    int *i = malloc(sizeof(int)), *j = malloc(sizeof(int)), *starty = malloc(sizeof(int)),
        *startx = malloc(sizeof(int)), *lineX = malloc(sizeof(int));

    // Aloca memória para um char que será um placeholder para as coordenadas
    char *c = malloc(sizeof(char));

    // Pega os limites da janela atual
    getmaxyx(w, *starty, *startx);

    // declara e inicializa a linha de separação
    char line[] = "+-----+-----+-----+-----+-----+-----+-----+-----+";

    // Calcula a coordenada inicial para a altura do tabuleiro
    *starty = (*starty / 2) - (TAM_TAB / 8);

    // Calcula a coordenada inicial para a largura do tabuleiro
    *startx = (*startx / 2) - (strlen(line) / 2);

    // For para iterar sobre as linhas
    for (*i = 0; *i < (TAM_TAB / 8); (*i)++)
    {
        // Calcula a coordenada x para a linha
        *lineX = ((*i * 2) + *starty) + 2;

        // Imprime a linha de separação
        mvwprintw(w, *lineX, *startx, line);

        // c recebe a coordenada "simbólica" y da casa do tabuleiro
        *c = (*tab).casas[TAM_TAB - ((*i + 1) * 8)].y;

        // Imprime a coordenada simbólica
        mvwprintw(w, *lineX + 1, (*startx - 2), "%c | ", *c);

        // Itera sobre as colunas
        for (*j = 1; *j <= TAB_WIDTH; ++(*j))
        {
            // Imprime sobre a divisória das linhas
            mvwaddch(w, *lineX + 1, (*startx) + (FIELD_SIZE * (*j)), '|');
        }
    }
    
    // Imprime a linha final de separação
    mvwprintw(w, ((*i * 2) + *starty) + 2, *startx, line);
    
    // Libera as posições de memória utilizadas para a exibição do tabuleiro
    free(i);
    free(startx);
    free(starty);
    free(c);

    // Atualiza a janela
    wrefresh(w);

}