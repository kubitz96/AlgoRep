#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp;
const int *read_file(const char*, int *, int *);
int **alloc_matrix(const int*, int, int);
void fillmatrix(int **, const int*, int, int);
void check_diagonal(int **, int , int);

int main(void){
    const int *buffer;
    int **matrix;
    int rows, cols;
    buffer = read_file("input.txt", &rows, &cols);
    matrix = alloc_matrix(buffer, rows, cols);
    fillmatrix(matrix, buffer, rows, cols);
    check_diagonal(matrix, rows, cols);
}

void check_diagonal(int **matrix, int rows, int cols){
    int d;
    int sum1 = 0;
    int sum2 = 0;
    printf("%s", "_____ Diagonale 1 _____\n");
    for(int i = 0; i<rows; i++){
        d++;
        for(int j = 0; j<cols-d; j++){
            sum1 += matrix[i][j];
            printf("Matrix[%d][%d]: %d\n", i, j, matrix[i][j]);
        }
    }
    
    int r = cols+1;
    printf("%s", "_____ Diagonale 2 _____\n");
    for(int i = 0; i<rows; i++){
        r--;
        for(int j = r; j<cols; j++){
            sum2 += matrix[i][j];
            printf("Matrix[%d][%d]: %d\n", i, j, matrix[i][j]);
        }
    }

    if (sum1 > sum2){
        printf("%s", "La prima diagonale è > della seconda!");
    }
    else{
        printf("%s", "La seconda diagonale è > della prima!");
    }
}

const int *read_file(const char* filename, int *rows, int *cols){
    int count = 0;
    const int *buffer;
    if ((fp = fopen(filename, "r+")) != NULL){
        if (count==0){
            fscanf(fp, "%d", rows);
            count++;
        }
        if (count==1){
            fscanf(fp, "%d", cols);
        }
        int dim = (*rows) * (*cols);
        buffer = (int *) malloc( dim * sizeof(int));
        int i = 0;
        while(!feof(fp)){
            fscanf(fp, "%d", &buffer[i]);
            i++;
        }
        fclose(fp);
        printf("%s","Buffer: ");
        for(int i = 0; i<dim; i++){
            printf("%d", buffer[i]);
        }
        puts("\n");
    } 
    else{
        printf("File cannot be opened!");
    }

    return buffer;
}

int **alloc_matrix(const int* buffer, int rows, int cols){
    int **matrix;

    matrix = (int **) malloc(rows * sizeof(int*));
    if (matrix == NULL){
        printf("%s", "Allocazione non disp.");
    } 
    else{
        for(int i = 0; i<cols; i++){
            matrix[i] = (int *) malloc(cols*sizeof(int));
        }
    }

    return matrix;
}

void fillmatrix(int **matrix, const int*buffer, int rows, int cols){
    size_t e = 0;
    for(size_t i = 0; i<rows; i++){
        for(size_t j = 0; j<cols; j++){
            matrix[i][j] = buffer[e];
            e++;
        }
    }

    for(size_t i=0; i<rows; i++){
        for(size_t j=0; j<cols; j++){
            printf("Matrix[%d][%d]: %d\n", i, j, matrix[i][j]);
        }
    }
    printf("%s", "==============\n");
}