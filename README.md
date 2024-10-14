# Objektinis-programavimas
**Programos aprašymas:** programa, kuri leidžia vartotojui suvesti arba nuskaityti duomenis apie studenta(vardą, pavardę, namų darbų rezultatus, egzamino rezultatus). Apskaičiuoja studentų galutinius rezultatus paga formulę: Galutinis = 0.4 x namų darbų rezultatai + 0.6 x egzamino įvertinimas. <br />
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

**Laiko matavimas** <br/>
Buvo atliekamas testavimas naudojant sugeneruotus 5 failus. Testavimas buvo atliktas **8** kartų ir iš gautų laikų buvo išvestas vidurkis. Žemiau pateikta kiekvieno failo testavimo rezultatai.

**Failas: Studentai 1000**
| VEIKSMAS | VYKDYMO VIDURKIS|
| --- | --- |
| Failo generavimas | 0.2257875 s |
| Failo nuskaitymas | 0.085952525 s |
| Failo grupavimas  | 0.0087121875 s |
| Failo rušiavimas  | 0.0053023875 s |
| Studentų išvedimas į smart filą | 0.1233054125 s |
| Studentų išvedimas į dumb filą | 0.0394200375 s |

**Failas: Studentai 10000**
| VEIKSMAS | VYKDYMO VIDURKIS|
| --- | --- |
| Failo generavimas | 0.2257875 s  |
| Failo nuskaitymas | 0.085952525 s |
| Failo grupavimas  | 0.0087121875 s |
| Failo rušiavimas  | 0.0053023875 s |
| Studentų išvedimas į smart filą | 0.1233054125 s |
| Studentų išvedimas į dumb filą | 0.0394200375 s |

**Failas: Studentai 100000**
| VEIKSMAS | VYKDYMO VIDURKIS |
| --- | --- |
| Failo generavimas |                |
| Failo nuskaitymas |                |
| Failo grupavimas  |                |
| Failo rušiavimas  |                |
| Studentų išvedimas į smart filą |               |
| Studentų išvedimas į dumb filą |               |

**Failas: Studentai 1000000**
| VEIKSMAS | VYKDYMO VIDURKIS |
| --- | --- |
| Failo generavimas |                |
| Failo nuskaitymas |                |
| Failo grupavimas  |                |
| Failo rušiavimas  |                |
| Studentų išvedimas į smart filą |               |
| Studentų išvedimas į dumb filą |               |

**Failas: Studentai 10000000**
| VEIKSMAS | VYKDYMO VIDURKIS|
| --- | --- |
| Failo generavimas |                |
| Failo nuskaitymas |                |
| Failo grupavimas  |                |
| Failo rušiavimas  |                |
| Studentų išvedimas į smart filą |               |
| Studentų išvedimas į dumb filą |               |
