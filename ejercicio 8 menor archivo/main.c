#include <stdio.h>
#include <stdlib.h>



int menor(FILE *archi,int menor1);

int main()
{
    system("COLOR B");
    FILE *archi= fopen("ARCH","a+b");
    int arre[]= {4,2,5,4};
    int validos =4 ;
    int num;
    if(archi)
    {
        for(int i=0; i<validos; i++)
        {
            num=arre[i];
            fwrite(&num,sizeof(int),1,archi);

        }

        fclose(archi);
        archi=fopen("ARCH","rb");
        while(!feof(archi))
        {
            int cant=fread(&num,sizeof(int),1,archi);
            for(int i=0; i<cant; i++)
            {
                printf("%d",num);
            }
        }
        fclose(archi);
    }
    else
    {
        printf("ERROR \n");
    }
    int menor1=0;
    printf(" \n El menor es %d \n",menor(archi,menor1));
    return 0;
}

int menor(FILE *archi,int menor1)
{
    int num=0;
    archi=fopen("ARCH","r+b");
    fread(&num,sizeof(int),1,archi);
    menor1=num;
    if(feof(archi))
    {
        fread(&num,sizeof(int),1,archi);

        if(num<menor1)
        {
            menor1=num;
            fread(&num,sizeof(int),1,archi);
/// VER DE PASARLE LA POSICION EN LA QUE SE ENCUENTRA EL ARCHIVO PARA QUE VUELVA A LEER Y BUSQUE EL MENOR
             menor(archi,menor1);
        }
        else
        {
            menor(archi,menor1);
        }
    }

    fclose(archi);
    return menor1;

}


/**
agregar(nodo){
 lista =nuevo nodo

 ultimo = buscarUltimo();
 ultimo -> sig = nuevo nodo;

 PARA AGREGAR LISTA:

 1) Se crea un nuevo nodo
 2) funcion busca ultimo
 3)







}


+/
