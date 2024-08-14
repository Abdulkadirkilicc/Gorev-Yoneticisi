
# Görev Yöneticisi

## Projenin Amacı

Bu proje, kullanıcıların görevlerini kolayca yönetmelerine yardımcı olacak basit bir komut satırı görev yöneticisi uygulamasıdır. Kullanıcılar görev ekleyebilir, görevleri listeleyebilir, tamamlayabilir ve tamamlanmış görevleri silebilirler. Ayrıca, görevler dosyaya kaydedilerek uygulama kapatıldığında bile veri kaybını önler.

## Özellikler

- **Görev Ekleme:** Kullanıcılar yeni görevler ekleyebilir.
- **Görev Listeleme:** Tüm görevleri listeler ve her bir görev için tamamlanma durumunu gösterir.
- **Görev Tamamlama:** Belirli bir görevi tamamlanmış olarak işaretler.
- **Tamamlanmış Görevleri Silme:** Tamamlanmış görevleri listeden kaldırır.
- **Veri Kaydetme ve Yükleme:** Görevler, bir dosyaya kaydedilir ve uygulama yeniden başlatıldığında dosyadan yüklenir.

## Kurulum

1. **Depoyu Klonlayın:**
   ```bash
   git clone https://github.com/kullanici_adiniz/gorev-yoneticisi.git
   ```
   
2. **Proje Klasörüne Gidin:**
   ```bash
   cd gorev-yoneticisi
   ```

3. **Derleme:**
   C dosyalarını derlemek için aşağıdaki komutu kullanın:
   ```bash
   gcc -o gorev_yoneticisi main.c
   ```

4. **Çalıştırma:**
   Derlenmiş programı çalıştırın:
   ```bash
   ./gorev_yoneticisi
   ```

## Kullanım

Program çalıştırıldığında, aşağıdaki menü seçenekleri sunulacaktır:

1. **Görev Ekle:** Yeni bir görev ekler.
2. **Görevleri Listele:** Mevcut görevleri ve durumlarını listeler.
3. **Görevi Tamamla:** Belirtilen numaradaki görevi tamamlanmış olarak işaretler.
4. **Tamamlanmış Görevleri Sil:** Tamamlanmış görevleri listeden kaldırır.
5. **Çıkış:** Programı kapatır ve mevcut görevler dosyaya kaydedilir.

### Örnek Kullanım

- Görev eklemek için: Program menüsünden `1` seçeneğini seçin ve görev açıklamasını girin.
- Görevleri listelemek için: `2` seçeneğini seçin.
- Görevi tamamlamak için: `3` seçeneğini seçin ve tamamlanacak görevin numarasını girin.
- Tamamlanmış görevleri silmek için: `4` seçeneğini seçin.
- Programdan çıkmak için: `5` seçeneğini seçin.

## Katkıda Bulunma

Eğer projeye katkıda bulunmak isterseniz, lütfen bir pull request gönderin veya sorunlarınızı (issue) paylaşın. Her türlü katkı ve geri bildirim kabul edilir.

