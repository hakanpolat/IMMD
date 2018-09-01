#### Kontrol kartı notlar:
**Eklenen çıkarılan malzemelerin siparişini düşünmek lazım**
1. DC Link Cap yeniden eklendi. Footprint aynı, boyutlar aynı gözüküyor.
2. PWM buffer PN değişti. Şematik + layoutta değişecek.
3. 0.1uF DC Link cap birer tane daha eklendi.
4. Yazılar, isimler vs eklendi, ayarlandı.
5. PWM buffer'lar NC7WZ16P6X olarak değiştirildi (Kütüphane yeni komponent, Footprint vs aynı).
6. Voltaj ölçümü direnç voltajı yetmiyor, değiştirildi. 1206 eklendi. Linkler yenilendi. 500V dayanımlı tek direnç kullanıldı.
7. Measurement'ta büyük oranda layout değişikliği yapıldı. Genel olarak bottom'dan topa aktarıldı.
8. Measurement opamplara ve AMC'lere kapasitör eklendi.
9. Test point eklenecek.
10. Rule ile yapılan clearance'lar bir kontrol edilmeli.
11. 15V'un kapasitörlere poşigon atıldı.
12. PWM buffer'ları düzenlendi (1 pair), konektör ile DSP'nin arasına alındı. Tek sorun 3.3V uzaklığı. O da bottom layerdan taşındı.
13. Bir köprüden geçecek sinyaller çıkarıldı ve köprü genişliği kontrol edildi.
14. JTAG tarafından düzenlemeler yapıldı (hizalama vs). Henüz tamamlanmadı.
