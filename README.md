# Objektinis-programavimas
## Programos aprašymas <br/>
Programa, kuri leidžia vartotojui suvesti arba nuskaityti duomenis apie studenta(vardą, pavardę, namų darbų rezultatus, egzamino rezultatus). Apskaičiuoja studentų galutinius rezultatus paga formulę: Galutinis = 0.4 x namų darbų rezultatai + 0.6 x egzamino įvertinimas. <br />
*Namų darbų rezultatai - vartotojui leidžiama pasirinkti ar namų darbų rezultatus skaičiuoti su mediana ar gauti jų vidurkį.*<br/>
<br/>

**V0.2 atnaujinimas:** Vartotojas nuo šiol gali pasirinkti failu ne tik nuskaityti, bet ir sugeneruoti. Naudotojui pasirinkus generavimo metodą, bus sugeneruojami 5 skirtingi failai: studentai 1000, studentai 10000, studentai 100000, studentai 1000000 studentai 10000000.
<br/>

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
  
**Failas: Studentai 1000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.0159676167 s | |
| Failo grupavimas  | 0.0019471667 s | |
| Failo rušiavimas  | 0.0002987667 s | |
| Studentų išvedimas į smart failą | 0.0030953833 s | |
| Studentų išvedimas į dumb failą | 0.00191965 s | |

**Failas: Studentai 10000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.0985081333 s | |
| Failo grupavimas  | 0.0076673167 s | |
| Failo rušiavimas  | 0.0052359 s | |
| Studentų išvedimas į smart failą | 0.0130139 s | |
| Studentų išvedimas į dumb failą | 0.0099617833 s | |

**Failas: Studentai 100000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 0.751953875 s | |
| Failo grupavimas  | 0.0603202 s | |
| Failo rušiavimas  | 0.0599166875 s | |
| Studentų išvedimas į smart failą | 0.1135195 s | |
| Studentų išvedimas į dumb failą | 0.0726314667 s | |

**Failas: Studentai 1000000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 8.2884075 s | |
| Failo grupavimas  | 0.851942625 s | |
| Failo rušiavimas  | 0.71661653 s | |
| Studentų išvedimas į smart failą | 1.0000588167 s | |
| Studentų išvedimas į dumb failą | 0.6644465 s| |

**Failas: Studentai 10000000**
| VEIKSMAS | VYKDYMO VIDURKIS(vector) | VYKDYMO VIDURKIS(list) |
| --- | --- | --- |
| Failo nuskaitymas | 73.1526125 s | |
| Failo grupavimas  | 5.68810375 s | | 
| Failo rušiavimas  | 6.61167625 s | | 
| Studentų išvedimas į smart failą | 10.1445716667 s | |
| Studentų išvedimas į dumb failą | 7.6079633333 s | |
