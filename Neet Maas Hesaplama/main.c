#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int asgrmaas;  // asgari ücret 
int *brutmaas;
int netmaas;
int sgk_primi;
int issizlik_primi;
int gelir_vergisi;
int damga_vergisi;
int issizlik_kesintisi=75;
int toplam;
char yildiz[50];

int serino;
double tcno;   // TC kimlik numaras� 
char statu;       // calisma pozisyonu 
int mdnhal;     // Medeni hal durumu 
char ad,soyad;
int csayisi,cikis;    // cocuk sayisi 
int esdrm ; // es durumu

void main() {

	do {
		asgrmaas = 8506;
		brutmaas = &asgrmaas;
            printf("\t                      **...Sosyal Guvenlik Kurumu net maas hesaplama programnina hosgeldiniz...**\n");
            printf("\t \n **Maas suanki net asgari ucret(8506)uzerinden hesaplanir ...**\n");
            
            /*printf("\n''Luttfen TC kimlik numaranizi giriniz'' = ");
            scanf("%d",&tcno);*/

            do {
                    printf("\n''Luttfen SGK kurumu 5 haneli seri numaranizi giriniz'' = ");
                    scanf("%d", &serino);

                    if (serino > 99999 || serino < 9999) {
                    printf("Lutfen 5 haneli sayi giriniz giriniz!\n");  
                    }	
            } while (serino > 99999 || serino < 9999);
	
	printf("\n AD: ");
	scanf("%s", &ad);
	
	printf("\n SOYAD: ");
	scanf("%s", &soyad);
	
                do { 
                    printf("\n **Calistiginiz statuyu yandaki rakamlarla belirtiniz !** \n (Isci (1) & Memur (2)  '' = ");
                    scanf("%d", &statu);

                        if(statu!=1 && statu!=2){
                        printf("Lutfen yukaridaki rakamlardan birini giriniz sayi giriniz giriniz!\n");         
                        }	
                } while (statu! = 1 && statu! = 2);
                    
                if (statu == 1 ) {
                asgrmaas = asgrmaas + 4306;	
                } else if (statu == 2) {
                asgrmaas = asgrmaas + 3444;	
                }
	
                do {
                printf("\n **Medeni halinizi yandaki rakamlarla belirtiniz** \n (Evli (1) ,Dul (2) , Bekar (3) =  ");
                scanf("%d", &mdnhal);

                        if(mdnhal! = 1 && mdnhal! = 2 && mdnhal! = 3){
                        printf("Lutfen yukaridaki rakamlardan birini giriniz sayi giriniz giriniz!\n");          
                        }

                } while (mdnhal!=1 && mdnhal!=2 && mdnhal!=3);
                        
                    if (mdnhal == 1) {
                    asgrmaas = asgrmaas + 100;
                    }
                    else if (mdnhal == 2 ) {
                    asgrmaas = asgrmaas + 200;	
                    }
                    else if (mdnhal == 3) {
                    asgrmaas = asgrmaas + 0;	
                    }
		
                do{
                printf("\n **Es calisma durumunu yandaki rakamlarla belirtiniz** \n (Evet (1) ,Hayir (2) , =  ");
                scanf("%d",&esdrm);
                if(esdrm!=1 && esdrm!=2){
                        printf("Lutfen yukaridaki rakamlardan birini giriniz sayi giriniz giriniz!\n");           
                        }
                }while(esdrm!=1 && esdrm!=2);    
                    
                if(esdrm == 2){
                    asgrmaas=asgrmaas+100;
                }
		
                    printf("\n **Cocuk sayinizi giriniz** =  ");
                    scanf("%d",&csayisi);
                    {
                        if(csayisi == 0)
                        asgrmaas=asgrmaas+0;
                        else if(csayisi==1)
                        asgrmaas=asgrmaas+100;
                        else if(csayisi==2)
                        asgrmaas=asgrmaas+200;
                        else if(csayisi==3)
                        asgrmaas=asgrmaas+300;
                        else if(csayisi==4)
                        asgrmaas=asgrmaas+400;
                        else
                        asgrmaas=asgrmaas+500;	                  
                    }

                    sgk_primi=*brutmaas*14/100;
                    issizlik_primi=*brutmaas*5/100+15/100;
                    gelir_vergisi=*brutmaas*1/100;
                    damga_vergisi=*brutmaas*1/40;
                    netmaas=*brutmaas-(sgk_primi+issizlik_primi+gelir_vergisi+damga_vergisi);
                    toplam=netmaas*12-(issizlik_kesintisi*7);
                    
                    printf("***********************************");
                    printf(" \t\n SGK PRIMI: %d \n",sgk_primi);
                    printf(" \t\n ISSIZLIK VERGISI: %d \n",issizlik_primi);
                    printf(" \t\n GELIR VERGISI: %d \n",gelir_vergisi);
                    printf(" \t\n DAMGA VERGISI: %d \n",damga_vergisi);
                    printf("***********************************");
                    printf(" \t\n BRUT MAASINIZ: %d \n",*brutmaas);
                    printf(" \t\n NET MAAS: %d \n",netmaas);
                    
                    //////////////////////////////////////////
                    printf("***********************************");
                    printf(" \t\n OCAK: %d \n",netmaas);
                    printf(" \t\n SUBAT: %d \n",netmaas);
                    printf(" \t\n MART: %d \n",netmaas);
                    printf(" \t\n NISAN: %d \n",netmaas);
                    printf(" \t\n MAYIS: %d \n",netmaas);
                    printf(" \t\n HAZIRAN: %d \n",netmaas-issizlik_kesintisi);
                    printf(" \t\n TEMMUZ: %d \n",netmaas-issizlik_kesintisi-15);
                    printf(" \t\n AGUSTOS: %d \n",netmaas-issizlik_kesintisi-100);
                    printf(" \t\n EYLUL: %d \n",netmaas-issizlik_kesintisi-183);
                    printf(" \t\n EKIM: %d \n",netmaas-issizlik_kesintisi-204);
                    printf(" \t\n KASIM: %d \n",netmaas-issizlik_kesintisi);
                    printf(" \t\n ARALIK: %d \n",netmaas);
                    printf("***********************************");
                    printf(" \t\n TOPLAM: %d \n",toplam);
                    printf("***********************************");
                    ////////////////////////////////////////
                    
                FILE *fp;
                if((fp=fopen("sgk.txt","a"))==NULL){
                    printf("dosya bulunamadi");
                }
                fprintf(fp,"***********************************",yildiz);
                fprintf(fp," \t\n SGK NO : %d \t ",serino);
                fprintf(fp," \t\n BRUT MAAS : %d \n ",*brutmaas); 
                fprintf(fp," \t\n NET MAAS : %d \n ",netmaas); 
                    fprintf(fp,"  \t\n OCAK: %d \n",netmaas);
                    fprintf(fp," \t\n SUBAT: %d \n",netmaas);
                    fprintf(fp," \t\n MART: %d \n",netmaas);
                    fprintf(fp," \t\n NISAN: %d \n",netmaas);
                    fprintf(fp," \t\n MAYIS: %d \n",netmaas);
                    fprintf(fp," \t\n HAZIRAN: %d \n",netmaas-issizlik_kesintisi);
                    fprintf(fp," \t\n TEMMUZ: %d \n",netmaas-issizlik_kesintisi-15);
                    fprintf(fp," \t\n AGUSTOS: %d \n",netmaas-issizlik_kesintisi-100);
                    fprintf(fp," \t\n EYLUL: %d \n",netmaas-issizlik_kesintisi-183);
                    fprintf(fp," \t\n EKIM: %d \n",netmaas-issizlik_kesintisi-204);
                    fprintf(fp," \t\n KASIM: %d \n",netmaas-issizlik_kesintisi);
                    fprintf(fp," \t\n ARALIK: %d \n",netmaas);
                    fprintf(fp," \t\n TOPLAM: %d \n",toplam);
                    fprintf(fp,"***********************************",yildiz);
                    
                    printf("\n Yeni bir net maas hesaplamak icin (0) tuslayiniz cikmak icin (1) tuslayiniz = ");
                    
                
                    scanf("%d",&cikis);
                    system("cls");

} while(cikis == 0);
    if (cikis == 1) {
        printf("KAPANIYOR....");
        Sleep(3000);
        exit(EXIT_SUCCESS);
    }	
}



