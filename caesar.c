#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// argc -> girilen argüman sayısı (arg counter)
// argv -> girilen argümanlar (arg vector)
// bir karakter dizini int e çevirilmek isteniyorsa atoi(str) yazılabilir (sdlib.h)
// argv[0] -> Programın ismidir. (caesar)
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // arg dizimdeki 1. indisteki stringi atoi fonksiyonuyla key değişkenine atadım.
        const int key = atoi(argv[1]);
        // Hatalı giriş yapılırsa diye kullanıcam
        bool valid = true;
        // Dizinin uzunluğunu length değişkeninde sakladım
        int length = strlen(argv[1]);
        // bu döngüyü sayı kontrolü yapmak için kullandım
        for (int i = 0; i < length; i++)
        {
            // Sayı olmayan bir şey algılarsa döngü sona erer.
            if (isdigit(argv[1][i]) == false) // [dizinin 1.elemanı][o elemanın karakterleri]
            {
                valid = false;
                i = length;
            }
        }
        // Döngü başarıyla biterse ve valid bool değeri true kalırsa, geçerli bir anahtarımız olur ve devam edebiliriz
        if (valid)
        {
            string plain = get_string("plaintext: ");
            int plainLength = strlen(plain);

            for (int i = 0; i < plainLength; i++)
            {
                if (islower(plain[i]))
                {
                    if (plain[i] + key >  'z')
                    {
                        // Seçtiğimiz harfin değerini alır ve toplam adımları ekler, ardından tam dönüş için 'z'yi çıkarır
                        int keyRest = (plain[i] + key) - ('z');
                        // Kalan adım miktarının hala alfabenin tüm uzunluğunun değerinden büyük olup olmadığını kontrol eder
                        if (keyRest >= 'z' - 'a')
                        {
                            // keyRest 25'ten büyükken bu döngüye devam ediyoruz
                            while (keyRest >= ('z' - 'a'))
                            {
                                // Her yineleme, toplamdan 26 (alfabenin uzunluğunu) çıkarır
                                keyRest = keyRest - (26);
                            }

                            // İlk harf değeri + yeni kalan hala z'den büyükse, farkı alıp 'a' değerine ekleyerek turu son kez sararız
                            if (plain[i] + keyRest > 'z')
                            {
                                keyRest = plain[i] + keyRest - 'z';
                                plain[i] = 'a' + keyRest - 1;
                            }
                            // keyRest + ilk harf değeri 'z' değerinden büyük değilse, ilk harf değerini alırız ve keyRest'da kalan adım sayısını ekleriz
                            else
                            {
                                plain[i] = 'a' + keyRest - 1;
                            }
                        }
                        else
                        {
                                plain[i] = 'a' + keyRest - 1;
                        }
                    }
                    else if (plain[i] + key <= 'z')
                    {
                        plain[i] = plain[i] + key;
                    }
                }

                if (isupper(plain[i]))
                {
                    // ASCII
                    if (plain[i] + key >  'Z')
                    {                        
                        int keyRest = (plain[i] + key) - 'Z';
                        if (keyRest > 'Z' - 'A')
                        {
                            while (keyRest >= ('Z' - 'A'))
                            {
                                keyRest = keyRest - ('Z' - 'A');
                            }
                            if (plain[i] + keyRest > 'Z')
                            {
                                keyRest = plain[i] + keyRest - 'Z';
                                plain[i] = 'A' + keyRest - 1;
                            }
                            else
                            {
                                plain[i] = 'a' + keyRest - 1;
                            }
                        }
                        else
                        {
                            plain[i] = 'A' + keyRest - 1;
                        }
                    }
                    else if (plain[i] + key <= 'Z')
                    {
                        plain[i] = plain[i] + key;
                    }
                }

            }

            printf("ciphertext: %s\n", plain);
        }
        // Kullanılamayan bir anahtar tespit edersek uygun bir anahtar isteriz
        else
        {
            printf("Usage: ./caesar KEY\n 1");            
            return 1;
        }

    }
    // Çok fazla argüman girildiyse, uygun bir anahtar isteriz
    else if (argc != 2)
    {
        printf("Usage: ./caesar KEY\n 1");        
        return 1;
    }

}