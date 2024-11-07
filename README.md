# Objektinis-programavimas
## Programos aprašymas <br/>
Programa, kuri leidžia vartotojui suvesti arba nuskaityti duomenis apie studenta(vardą, pavardę, namų darbų rezultatus, egzamino rezultatus). Apskaičiuoja studentų galutinius rezultatus paga formulę: Galutinis = 0.4 x namų darbų rezultatai + 0.6 x egzamino įvertinimas. <br />
*Namų darbų rezultatai - vartotojui leidžiama pasirinkti ar namų darbų rezultatus skaičiuoti su mediana ar gauti jų vidurkį.*<br/>
<br/>

**V0.2 atnaujinimas:** Vartotojas nuo šiol gali pasirinkti failu ne tik nuskaityti, bet ir sugeneruoti. Naudotojui pasirinkus generavimo metodą, bus sugeneruojami 5 skirtingi failai: studentai 1000, studentai 10000, studentai 100000, studentai 1000000 studentai 10000000.
<br/>
v0.3 atnaujinimas
v1.0 atnaujinimas

**Failų paaiškinimas:**
* main.cpp yra pagrindinis failas
* Stud.cpp faile surašytos visi programoje naudojami metodai
* Files.cpp faile surašyti metodai naudojami failų generavimui ir nuskaitymui
* MyLib.h faile aprašytos visos pogramoje naudojamos bibliotekos
* Stud.h faile aprašyta Stud struktūra, kuri aprašo studentą ir metodų deklaracijos
* Timer.h faile aprašytas laiko skaičiavimo klasė.
<a/>

**Metodai:**
* Vartotojas turi pasirinkimą ar nori studento informacija nuskaityti nuo tekstinio failo ar įrašyti rankiniu būdu
* Įrašinėjant rankiniu būdu, vartotojas turi galimybe sugeneruoti atsitiktinius namų darbų ir egzamino rezultatus
* Vartotojas turi galimyę galutinį rezultatą išspausdinti arba skaičiuojant su namų darbų mediana, arba su namų darbų vidurkiu. 

**Nauji metodai:**
* Sugeneruojami 5 nauji failai
* Nauji 5 failai yra nuskaitomi ir sugrupuojami pagal galutinį pažymį. Jeigu galutinis pažymys yra nemažesnis už 5, tada studentas yra priskiriamas prie smart studentu grupes, kitu atveju studentas priskiriamas prie dumb studentu grupes
* Naudotojui leidžiama pasirinkti pagal kurį aspektą išrušiuoti studentus juos įrašinėjant į rezultatų failus.
<a/>
  
  
**Išsimčių valdymas:**
* Klausimuose, kuriuose reikalaujama vartotojo pasirinkti vieną iš dviejų variantų yra naudojama try and catch norint apsaugoti nuo neteisingų įvedimų ir taip pat sistemos lūžimo, jeigu būtų įvesta raidė
* Norint įvesti namų darbų ar egzamino pažymį vartotojas yra apribojamas sveikaisiais skaičiais nuo 1 iki 10
* Nuskaitant failą yra tikrinama ar failas atsidaro, ar nuskaitytoje eilutėje yra namų darbų įrašai ir ar įrašyti namų darbų duomenys atitinka nustatytus standartus(sveikieji skaičiai nuo 1 iki 10 ir ar nėra įrašyta raidė). Pasitaikius išimčiai išmetama atitinkama klaida.

## Programos testavimas <br/>
Buvo atliekamas testavimas naudojant sugeneruotus 5 failus. Testavimas buvo atliktas **8** kartus ir iš gautų programos veikimo laikų buvo išvestas vidurkis. Žemiau pateikta kiekvieno failo testavimo rezultatai.

**Kompiuterio su kuriuo buvo atliekami testai specifikacijos:**
* CPU: Intel(R) Core(TM) Ultra 7 155H **3.80 GHz**
* RAM: 16 GB
* SDD: 1 TB
  
### Failas: Studentai 1000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.0159676167 s | 0.0123800667 s |
| Failo grupavimas  | 0.0019471667 s | 0.0013408 s |
| Failo rušiavimas  | 0.0002987667 s | 0.0004841333 s |
| Studentų išvedimas į smart failą | 0.0030953833 s | 0.0031049833 s |
| Studentų išvedimas į dumb failą | 0.00191965 s | 0.0015635833 s |

**Antra strategija**

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 0.01044758 s | 0.019020 s|
| Failo rušiavimas                   | 0.0003314 s | 0.000228 s|
| Failo grupavimas                   | 0.00020226 s | 0.000085 s|
| Studentų išvedimas į smart failą   | 0.00250062 s | 0.003435 s|
| Studentų išvedimas į dumb failą    | 0.00140596 s | 0.016829 s|

**Trečia strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 0.0102307 s | 0.020861 s|
| Failo rušiavimas                   | 0.0002818 s | 0.0000924 s|
| Failo grupavimas                   | 0.0000639 s | 0.000096 s|
| Studentų išvedimas į smart failą   | 0.0025763 s | 0.002818 s|
| Studentų išvedimas į dumb failą    | 0.0014608 s | 0.0013931 s|
<img src="https://github.com/user-attachments/assets/eccc11f9-8d10-4f0f-ba1e-778801e60b96" alt="Description" width="500"/>

----------------------

### Failas: Studentai 10000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.0985081333 s | 0.0950360667 s |
| Failo grupavimas  | 0.0076673167 s | 0.0069883833 s |
| Failo rušiavimas  | 0.0052359 s | 0.0018065333 s |
| Studentų išvedimas į smart failą | 0.0130139 s | 0.0126294 s |
| Studentų išvedimas į dumb failą | 0.0099617833 s | 0.0095311167 s |

**Antra strategija**

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 0.0816417 s | 0.085794 s|
| Failo rušiavimas                   | 0.00451634 s| 0.002108 s|
| Failo grupavimas                   | 0.00206306 s| 0.001052 s|
| Studentų išvedimas į smart failą   | 0.0117262 s | 0.011443 s|
| Studentų išvedimas į dumb failą    | 0.00751514 s| 0.009215 s|

**Trečia steategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 0.0905467 s | 0.092395 s|
| Failo rušiavimas                   | 0.0042513 s | 0.0012073 s|
| Failo grupavimas                   | 0.0006844 s | 0.0007259 s|
| Studentų išvedimas į smart failą   | 0.0109514 s | 0.0107712 s|
| Studentų išvedimas į dumb failą    | 0.0070881 s | 0.0078009 s|
<img src="https://github.com/user-attachments/assets/63142280-c428-4fac-8e0e-f90954c2518b" alt="Description" width="500"/>

----------------------

### Failas: Studentai 100000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.751953875 s | 0.7402695 s |
| Failo grupavimas  | 0.0603202 s | 0.0593329667 s |
| Failo rušiavimas  | 0.0599166875 s | 0.0301281833 s |
| Studentų išvedimas į smart failą | 0.1135195 s | 0.0991398333 s |
| Studentų išvedimas į dumb failą | 0.0726314667 s | 0.0720664 s |

**Antra strategija** </br>

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 0.6415938 s | 0.750852 s|
| Failo rušiavimas                   | 0.04712624 s | 0.015056 s|
| Failo grupavimas                   | 0.01539674 s | 0.016468 s|
| Studentų išvedimas į smart failą   | 0.07577556 s| 0.083223 s|
| Studentų išvedimas į dumb failą    | 0.05242182 s | 0.058222 s|

**Trečia steategija**

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 0.7453039 s | 0.6484366 s|
| Failo rušiavimas                   | 0.0495826 s | 0.0182077 s|
| Failo grupavimas                   | 0.0072107 s | 0.00993212 s|
| Studentų išvedimas į smart failą   | 0.0806573 s | 0.08293438 s|
| Studentų išvedimas į dumb failą    | 0.0531508 s | 0.05512132 s|
<img src="https://github.com/user-attachments/assets/0f1a3a84-f97b-48ce-8d63-2e0b298907b8" alt="Description" width="500"/>

----------------------

### Failas: Studentai 1000000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 8.2884075 s | 8.067803333 s |
| Failo grupavimas  | 0.851942625 s | 0.6628698333 s |
| Failo rušiavimas  | 0.71661653 s | 0.3381395 s |
| Studentų išvedimas į smart failą | 1.0000588167 s | 0.822413 s |
| Studentų išvedimas į dumb failą | 0.6644465 s | 0.5990218333 s |

**Antra strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                 | 6.098156 s  | 6.669537 s|
| Failo rušiavimas                  | 0.4605068  s | 0.121612 s|
| Failo grupavimas                  | 0.09134838 s  | 0.229607 s|
| Studentų išvedimas į smart failą  | 0.5152744  s | 0.616712 s|
| Studentų išvedimas į dumb failą    | 0.3749948  s | 0.458501 s|

**Trečia steategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 7.2731120 s | 6.109984 s|
| Failo rušiavimas                   | 0.5361923 s | 0.2250646 s|
| Failo grupavimas                   | 0.0622364 s | 0.08983824 s|
| Studentų išvedimas į smart failą   | 0.6443484 s | 0.6137734 s|
| Studentų išvedimas į dumb failą    | 0.4263662 s | 0.422014 s|
<img src="https://github.com/user-attachments/assets/8262d682-3c40-490e-a7ef-ca1db22052e6" alt="Description" width="500"/>

----------------------

### Failas: Studentai 10000000
**Pirma strategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 85.1526125 s | 82.4037 s |
| Failo grupavimas  | 5.68810375 s | 5.05564 s | 
| Failo rušiavimas  | 6.61167625 s | 6.0088216667 s | 
| Studentų išvedimas į smart failą | 10.1445716667 s | 9.6545516667 s |
| Studentų išvedimas į dumb failą | 7.6079633333 s | 7.146921 s |

**Antra strategija**

| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 62.77496 s | 64.72142 s|
| Failo rušiavimas                   | 5.333358 s | 3.13935 s|
| Failo grupavimas                    | 0.9854816 s| 1.25798 s|
| Studentų išvedimas į smart failą   | 5.417268 s | 6.67649 s|
| Studentų išvedimas į dumb failą    | 3.800548 s | 4.57997 s|

**Trečia steategija**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas                  | 72.2938054 s | 57.26326 s|
| Failo rušiavimas                   | 6.2909252 s | 2.928294 s|
| Failo grupavimas                   | 0.5787044 s | 0.8334702 s|
| Studentų išvedimas į smart failą   | 6.5107646 s | 5.74896 s|
| Studentų išvedimas į dumb failą    | 4.6918214  s| 3.777118 s|
<img src="https://github.com/user-attachments/assets/a41b041b-e72d-440e-ae99-5e3d2833e364" alt="Description" width="500"/>

## Testavimo išvados
Buvo testuojama programa naudojant dvi skirtingas struktūras: std::vector ir std::list. Programos veikimo laikai buvo lyginami. </br>
**Galima padaryti išvadas:**
* Lyginant vector ir list, programa sparčiau veikia, tačiau pokyčiai yra neženklūs. Atsižvelgiant į skaičius, didesnius pokyčius galime pastebėti tik didesniuose duomenų failuose.
* List yra labiau tinkamas naudoti su dideliais duomenų kiekiais, priešingai negu vector, kuris geriau veikia mažesnio duomenų kiekio failuose. 
