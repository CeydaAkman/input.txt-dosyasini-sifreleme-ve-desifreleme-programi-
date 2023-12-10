#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*Verilen metni þifreleme algoritmasý kullanarak þifreler.*/
void sifrele(char *metin, int anahtar){
	
    while (*metin){
    	
    	/*Karakterin bir harf olup olmadýðýna bakýlýr.*/
        if (isalpha(*metin)){
        	
        	/*Büyük harf ise taban deðeri 'A', küçük harf ise 'a' olacak þekilde belirlenir.*/
            char taban = isupper(*metin) ? 'A' : 'a';
            
            /*Karakteri þifreler ve yeni deðeri metin üzerine yazar.*/
            *metin = (char)(((int)(*metin - taban + anahtar) % 26) + taban);
            
        }
        
        /*Bir sonraki karaktere geçer.*/
        metin++;
        
    }
    
}

/*Verilen þifreli metni þifreleme algoritmasý kullanarak çözer.*/
void sifreCozme(char *metin, int anahtar){
	
    while (*metin){
    	
    	/*Karakterin bir harf olup olmadýðýna bakýlýr.*/
        if (isalpha(*metin)){
        	
        	/* Büyük harf ise taban deðeri 'A', küçük harf ise 'a' olacak þekilde belirlenir.*/
            char taban = isupper(*metin) ? 'A' : 'a';
            
            /*Karakteri çözer ve yeni deðeri metin üzerine yazar.*/
            *metin = (char)(((int)(*metin - taban - anahtar + 26) % 26) + taban);
            
        }
        
        /*Bir sonraki karaktere geçer.*/
        metin++;
        
    }
    
}

int main(){
	
	/*Dosya iþlemleri için gerekli dosya iþaretçileri tanýmlanýr.*/
    FILE *GirdiDosyasi, *SifrelenmisDosya, *CozulmusDosya;
    
    char metin[1000];
    int anahtar;

    /*Kullanýcýdan þifreleme/çözme anahtarý alýnýr.*/
    printf("Anahtar degerini giriniz: ");
    scanf("%d", &anahtar);

    /*Dosyalar açýlýr, açýlamazsa hata mesajý verilir ve program sonlanýr.*/
    GirdiDosyasi = fopen("input 1.txt", "r");
    SifrelenmisDosya = fopen("encrypted 1.txt", "w");
    CozulmusDosya = fopen("decrypted 1.txt", "w");

    if (GirdiDosyasi == NULL || SifrelenmisDosya == NULL || CozulmusDosya == NULL){
    	
        printf("Dosya acma hatasi!\n");
        return 1;
        
    }

    /*Girdi dosyasýndaki her satýr okunur, þifrelenir ve þifrelenmiþ dosyaya yazýlýr.*/
    while (fgets(metin, sizeof(metin), GirdiDosyasi) != NULL){
    	
        sifrele(metin, anahtar);
        fprintf(SifrelenmisDosya, "%s", metin);
        
    }

    /*Dosyalar kapatýlýr ve girdi dosyasý tekrar açýlýr.*/
    fclose(GirdiDosyasi);
    GirdiDosyasi = fopen("input 1.txt", "r");

    /*Þifrelenmiþ dosyadaki her satýr okunur, çözülür ve çözülmüþ dosyaya yazýlýr.*/
    while (fgets(metin, sizeof(metin), SifrelenmisDosya) != NULL){
    	
        sifreCozme(metin, anahtar);
        fprintf(CozulmusDosya, "%s", metin);
        
    }

    /*Dosyalar kapatýlýr.*/
    fclose(GirdiDosyasi);
    fclose(SifrelenmisDosya);
    fclose(CozulmusDosya);

    /*Ýþlem tamamlandý mesajý yazdýrýlýr.*/
    printf("Islem tamamlandi.\n");

    return 0;
    
}

