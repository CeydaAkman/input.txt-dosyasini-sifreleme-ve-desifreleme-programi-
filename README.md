# Bir input.txt Dosyasını Şifreleme ve Deşifreleme Programı:
Bu C programı, bir metni belirli bir anahtar değeri kullanarak şifrelemek ve ardından şifreli metni deşifre etmek için kullanılır. 
# Şifreleme:
1. Metinde bulunan yalnızca alfabedeki harfler şifrelenir. Diğer karakterler değiştirilmez.
2. Her harf, belirli bir anahtar değeri kadar kaydırılır. Örneğin, bir harf 'a' ise, bu harfi şifrelemek için anahtar değeri kadar sağa kaydırırız.
3. Kaydırma işlemi sonrasında alfabeden çıkan harfler için mod işlemi uygulanır. Böylece, alfabede bulunan harfler içerisinde kalırız.
4. Sonuç olarak elde edilen harflerle yeni bir şifreli metin oluşturulur.
# Şifre Çözme:
1. Önceki adımda oluşturulan şifreli metin, aynı anahtar değeri kullanılarak çözülür.
2. Yalnızca alfabedeki harfler çözülür, diğer karakterler değiştirilmez.
3. Her harf, belirli bir anahtar değeri kadar sola kaydırılır. Bu, şifreleme sırasında yapılan kaydırmanın tersidir.
4. Kaydırma işlemi sonrasında alfabeden çıkan harfler için mod işlemi uygulanır.
5. Sonuç olarak elde edilen harflerle yeni bir deşifre edilmiş metin oluşturulur.
# Kullanım:
1. input.txt Dosyası: Şifrelenecek metni içeren bu dosyayı oluşturun veya var olan bir dosyayı kullanın.
2. Programın anahtar değeri ve dosya isimleri sabit olarak kod içinde tanımlanmıştır.
1.	Anahtar değeri: “anahtar” değişkeniyle belirlenir. Kullanıcıdan girmesi istenir.
2.	Girdi dosyası: “input.txt” olarak adlandırılmalıdır.
3.	Şifrelenmiş metin dosyası: “encrypted.txt” olarak adlandırılmalıdır.
4.	Deşifre edilmiş metin dosyası: “decrypted.txt” olarak adlandırılmalıdır.
3. Programı Çalıştırma: Programı derleyip çalıştırdığınızda, input.txt dosyasındaki metni şifreler ve encrypted.txt dosyasına yazar. Daha sonra bu şifreli metni deşifre edip decrypted.txt dosyasına yazar.
4. Her dosyanın içeriği program tarafından oluşturulan sonuçları içerir.
# Test:
1.	Bu depoyu bilgisayarınıza indirin.
2.	Programı derleyin ve çalıştırın.
3.	Çıktıları kontrol edin:
1.	Şifrelenmiş metin dosyası (encrypted.txt) oluşturuldu mu?
2.	Deşifre edilmiş metin dosyası (decrypted.txt) oluşturuldu mu?
# Ekran Çıktıları:
![İŞLEM TAMAMLANDI](https://github.com/CeydaAkman/input.txt-dosyasini-sifreleme-ve-desifreleme-programi-/assets/148623804/9c94a127-925f-4f2b-a0ff-45cf29050123)

![DOSYA AÇMA HATASI](https://github.com/CeydaAkman/input.txt-dosyasini-sifreleme-ve-desifreleme-programi-/assets/148623804/43234d4b-f28e-4341-94ad-31f70b135cf6)

