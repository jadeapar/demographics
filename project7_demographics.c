// Jadea Parchment this program will sort the states by percentage//population whose ages are equal or greater than 65 yeears old.
//Write the results in the output file.
#include<stdio.h>
#include <string.h>
//different components of state information in a structure
struct state
{
        char statename[50];
        int pop20;
        int pop10;
        double belowfive;
        double beloweighteen;
        double sixtyfivegreater;
};
//function that sorts state list being declared
void sort_states(struct state list[], int n);

//main function
int main()
{
        char fileone[30];
        char filetwo[35]; 
    // accept input
        printf("Enter the file name: ");
        scanf("%s", fileone);

        FILE *firstfile = fopen(fileone, "r");
        FILE *lastfile;


        struct state list[100];
        int a, n = 0;  

        if(!feof(firstfile))
        {   
                //sort list
                while(fscanf(firstfile, "\n%[^,], %d, %d, %lf, %lf, %lf",
                                                                list[n].statename,
                                                                &list[n].pop20,
                                                                &list[n].pop10,
                                                                &list[n].belowfive,
                                                                &list[n].beloweighteen,
                                                                &list[n].sixtyfivegreater) != -1) {
                        if(!feof(firstfile)) 
                                n++;             
                }

                fclose(firstfile);

                sort_states(list, n);
//print output file name 
                strcpy(filetwo, "sorted_");
                strcat(filetwo, fileone);
                printf("Output file name:\n\n%s\n", filetwo);
        
                lastfile = fopen(filetwo, "w");

                for(a=0; a<n; a++)
                {
                    //put sorted information in output file
                                fprintf(lastfile, "%s,%d,%d,%.1lf,%.1lf,%.1lf\n",
                                                                list[a].statename,
                                                                list[a].pop20,
                                                                list[a].pop10,
                                                                list[a].belowfive,
                                                                list[a].beloweighteen,
                                                                list[a].sixtyfivegreater);
                }

                fclose(lastfile);// closes file 
        }
        return 0;
}
//function that sorts state list
void sort_states(struct state list[], int n)
{
        int k, l, m;
        struct state temp;

        for(k=0; k<n; k++)
        {
                m =k;
                for(l=k+1; l<n; l++)
                {
                        if(list[m].sixtyfivegreater < list[l].sixtyfivegreater)
                        {
                                m = l;
                        }
                }
                //swapping 
                temp = list[m];
                list[m] = list[k];
                list[k] = temp;
        }
}

