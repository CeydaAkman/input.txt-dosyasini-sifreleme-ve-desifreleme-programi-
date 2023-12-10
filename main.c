#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*Verilen metni �ifreleme algoritmas� kullanarak �ifreler.*/
void sifrele(char *metin, int anahtar){
	
    while (*metin){
    	
    	/*Karakterin bir harf olup olmad���na bak�l�r.*/
        if (isalpha(*metin)){
        	
        	/*B�y�k harf ise taban de�eri 'A', k���k harf ise 'a' olacak �ekilde belirlenir.*/
            char taban = isupper(*metin) ? 'A' : 'a';
            
            /*Karakteri �ifreler ve yeni de�eri metin �zerine yazar.*/
            *metin = (char)(((int)(*metin - taban + anahtar) % 26) + taban);
            
        }
        
        /*Bir sonraki karaktere ge�er.*/
        metin++;
        
    }
    
}

/*Verilen �ifreli metni �ifreleme algoritmas� kullanarak ��zer.*/
void sifreCozme(char *metin, int anahtar){
	
    while (*metin){
    	
    	/*Karakterin bir harf olup olmad���na bak�l�r.*/
        if (isalpha(*metin)){
        	
        	/* B�y�k harf ise taban de�eri 'A', k���k harf ise 'a' olacak �ekilde belirlenir.*/
            char taban = isupper(*metin) ? 'A' : 'a';
            
            /*Karakteri ��zer ve yeni de�eri metin �zerine yazar.*/
            *metin = (char)(((int)(*metin - taban - anahtar + 26) % 26) + taban);
            
        }
        
        /*Bir sonraki karaktere ge�er.*/
        metin++;
        
    }
    
}

int main(){
	
	/*Dosya i�lemleri i�in gerekli dosya i�aret�ileri tan�mlan�r.*/
    FILE *GirdiDosyasi, *SifrelenmisDosya, *CozulmusDosya;
    
    char metin[1000];
    int anahtar;

    /*Kullan�c�dan �ifreleme/��zme anahtar� al�n�r.*/
    printf("Anahtar degerini giriniz: ");
    scanf("%d", &anahtar);

    /*Dosyalar a��l�r, a��lamazsa hata mesaj� verilir ve program sonlan�r.*/
    GirdiDosyasi = fopen("input 1.txt", "r");
    SifrelenmisDosya = fopen("encrypted 1.txt", "w");
    CozulmusDosya = fopen("decrypted 1.txt", "w");

    if (GirdiDosyasi == NULL || SifrelenmisDosya == NULL || CozulmusDosya == NULL){
    	
        printf("Dosya acma hatasi!\n");
        return 1;
        
    }

    /*Girdi dosyas�ndaki her sat�r okunur, �ifrelenir ve �ifrelenmi� dosyaya yaz�l�r.*/
    while (fgets(metin, sizeof(metin), GirdiDosyasi) != NULL){
    	
        sifrele(metin, anahtar);
        fprintf(SifrelenmisDosya, "%s", metin);
        
    }

    /*Dosyalar kapat�l�r ve girdi dosyas� tekrar a��l�r.*/
    fclose(GirdiDosyasi);
    GirdiDosyasi = fopen("input 1.txt", "r");

    /*�ifrelenmi� dosyadaki her sat�r okunur, ��z�l�r ve ��z�lm�� dosyaya yaz�l�r.*/
    while (fgets(metin, sizeof(metin), SifrelenmisDosya) != NULL){
    	
        sifreCozme(metin, anahtar);
        fprintf(CozulmusDosya, "%s", metin);
        
    }

    /*Dosyalar kapat�l�r.*/
    fclose(GirdiDosyasi);
    fclose(SifrelenmisDosya);
    fclose(CozulmusDosya);

    /*��lem tamamland� mesaj� yazd�r�l�r.*/
    printf("Islem tamamlandi.\n");

    return 0;
    
}

