    #include <stdio.h>
    #include <string.h>

    int main (int argc, char *argv[]) {

        float cal[5][3][3]={0};
        char nombres[5][20];
        char asignaturas[3][20]={"Fisica",
                                "Quimica",
                                "Calculo"};

        float prom[5][3]={0};
        int opc = 0, opc2 = 0;
        int contE = 0;
        int selE=0;
        int aux = 0;

        do{
            printf("Seleccione una opcion:\n");
            printf("1.Registrar estudiante\n");
            printf("2.Registrar calificaciones\n");
            printf("3.Promedios por estudiante\n");
            printf("4.Promedios por asignatura\n");
            printf("5.Calificacione mas alta y baja por estudiante\n");
            printf("6.Calificacione mas alta y baja por asignatura\n");
    do{
                printf(">> ");
                aux = scanf("%d",&opc);
                if(aux != 1 || opc < 0){
                    printf("Ingrese una opcion valida\n");
                    while(getchar() != '\n');
                }
            }while (aux != 1 || opc < 0);
            switch (opc)
            {
            case 1:
                printf("Registre el nombre del estudiante %d:\n",contE+1);
                getchar();
                fgets(nombres[contE],20,stdin);
                contE++;
                break;
            case 2:
                printf("Seleccione el estudiante al cual desea registras las calificaciones:\n");
                for (int i = 0; i < contE; i++)
                {
                    printf("%d.%s",i,nombres[i]);
                }
                printf(">> ");
                scanf("%d",&selE);

                printf("Ingrese las calificaciones del estudiante %d:\n",selE+1);

                for (int i = 0; i < 3; i++)
                {
                    printf("%s\n",asignaturas[i]);
                    for (int j = 0; j < 3; j++)
                    {
                        printf("Nota %d: ",j+1);
                        scanf("%f",&cal[selE][i][j]);
                        prom[selE][i]+=cal[selE][i][j];
                    }
                    prom[selE][i]/=3;
                }
                break;
            case 3:
                float promAux = 0;
                printf("%s\t\t%s\t\t%s\t\tPromedio\t\tNombre\n",asignaturas[0],
                                                                asignaturas[1],
                                                                asignaturas[2]);
                for (int i = 0; i < contE; i++)
                {
                    promAux = (prom[i][0] + prom[i][1] + prom[i][2])/3;
                    printf("%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%s",prom[i][0],
                                                                prom[i][1],
                                                                prom[i][2],
                                                                promAux,
                                                                nombres[i]);
                }
                break;
            case 4:

                float promAsig[3]={0};
                printf("%s\t\t%s\t\t%s\n",asignaturas[0],
                                            asignaturas[1],
                                            asignaturas[2]);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < contE; j++)
                    {
                        promAsig[i]+=prom[j][i];
                    }
                    promAsig[i]/=contE;
                    printf("%.2f\t\t",promAsig[i]);
                }
                break;
            case 5:
                printf("Seleccione el estudiante del cual desea ver las notas:\n");
                for (int i = 0; i < contE; i++) {
                printf("%d. %s", i, nombres[i]);
                }
                    printf(">> ");
                    scanf("%d", &selE);
                    if (selE >= 0 && selE < contE) {
                    float max = cal[selE][0][0]; 
                    float min = cal[selE][0][0];

                    for(int i = 0; i < 3; i++) { 
                    for(int j = 0; j < 3; j++) { 
                    if(cal[selE][i][j] > max) max = cal[selE][i][j];
                    if(cal[selE][i][j] < min) min = cal[selE][i][j];
            }
        }
        
                printf("\nResultados para %s", nombres[selE]);
                printf("Calificacion mas alta: %.1f\n", max);
                printf("Calificacion mas baja: %.1f\n", min);
    } else {
                printf("Error: Estudiante no valido.\n");
    }
    break;

                case 6:
                    for (int i = 0; i < 3; i++) {
                        int ap = 0, rep = 0;
                        for (int j = 0; j < contE; j++) {
                            if (prom[j][i] >= 6.0) ap++; else rep++;
                        }
                        printf("%s -> Aprobados: %d, Reprobados: %d\n", asignaturas[i], ap, rep);
                    }
                    break;

            }
                    printf("Desea seleccionar otra opcion? 1.Si/2.No: ");
            scanf("%d",&opc2);
        }while(opc2==1);

        return 0;

    }
