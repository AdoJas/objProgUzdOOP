# ***Klasės*** ***ir*** ***struktūros***

## Kompiuterio komponentai naudoti testavimo metu 

|   Komponentas  |                   Pavadinimas                       |                      
|:--------------:|:---------------------------------------------------:|
|     **CPU**    |            `AMD Ryzen 5 3600 6-core`              |
|     **GPU**    |`G.Skill Trident Z RGB DDR4 16GB (2x8GB) 3200MHz`  |
|     **SSD**    |           `Samsung SSD 970 EVO Plus, 500GB`       |

# Penkių taisyklė
## Penkiu taisykle - metodai, sukurti saugiam ir patogiam objektiniam programavimui: 
> 1. Kopijavimo konstruktorius
> 2. Priskyrimo konstruktorius
> 3. Perkelimo konstruktorius
> 4. Perkelimo priskyrimo konstruktorius
> 5. Destruktorius

## Kopijavimo konstruktorius
Atsakingas uz kompleksini objekto kopijavima, kai objektas turi tuos pacius duomenis arba kintamuosius.

<p>studentasV(const studentasV &kita);</p>
## Priskyrimo konstruktorius  
Atsakingas uz kompleksinio objekto priskyrima. 

<p>studentasV& studentasV::operator=(const studentasV &kita)</p>      
## Perkelimo konstruktorius
Atsakingas uz kompleksinio objekto perkelima is vieno objekto i kita.

<p>studentasV::studentasV(studentasV&& kita) noexcept :
        studentasBase(),
        pazymiai(std::move(kita.pazymiai)),
        egzaminas(kita.egzaminas) </p>
## Perkelimo priskyrimo konstruktorius
Atsakingas uz kompleksinio objekto perkelima ir priskyrima naujam objektui.

<p>studentasV& studentasV::operator=(studentasV&& kita) noexcept </p>
## Destruktorius
Atsakingas uz kompleksinio objekto sunaikinima programai baigus veikti.

<p>studentasV::~studentasV()</p>
## Ivesties metodo perdengimas

<p> std::istream &operator>>(std::istream &inputas, studentasV &studentas){
    inputas >> studentas.vardas >> studentas.pavarde >> studentas.egzaminas;
    studentas.pazymiai.clear();
    int pazymys;
    while (inputas >> pazymys) {
        studentas.pazymiai.push_back(pazymys);
    }
    return inputas;
}</p>
## Isvesties metodo perdengimas

<p> std::ostream& operator<<(std::ostream& outputas, const studentasV &studentas) {
    outputas << studentas.vardas << " " << studentas.pavarde << " " << studentas.egzaminas << " ";
    for (int pazymys : studentas.pazymiai) {
        outputas << pazymys << " ";
    }
    return outputas;
}</p>
# ***Ka daro programa?***
>1. Leidzia dinamiskai arba statiskai ivesti studentu duomenis ir dirbti su jais.
>2. Leidzia ivedus studentu vardus ir pavardes generuoti ju pazymius ir dirbti su jais.
>3. Leidzia automatiskai atsitiktinai generuoti studentu vardus, pavardes ir ju pazymius, dirbti su jais.
>4. Leidzia nuskaityti duomenis is failo ir dirbti su tais duomenimis.
>5. Leidzia generuoti studentu duomenu faila su pazymiais, juos nuskaityti ir dirbti su jais.
>6. 5 funkcija, su pridetu pasirinkimu rusiuoti duomenis i skirtingus konteinerius(Vector, list, deque).


# ***Kaip pasinaudoti kodu? (Windows ir macOS)***
>1. Atsisiuntę ir išsisaugoję projekto failus savo kompiuteryje, atsisiųskite CLion IDE. [https://www.jetbrains.com/clion/download/#section=mac]
>2. Aktyvuokite CLion IDE su savo gautu kodu, kuris jums bus atsiūstas i el. pašto adresą, su kuriuo registravotės į JETBRAINS.
>3. Atlikę šiuos žingsnius, atsidarykite failus per CLion.
>4. Atidarius į failus, paspauskite ant Program.cpp du kartus.
>5. Viršuje iššokęs langelis praneš, kad reikia sukonfiguruoti CMake projektą.
>6. Paspauskite šį mygtuką ir nurodykite CMakeLists.txt failo vietą savo kompiuteryje.
>7. Atlikus šiuos žingsnius, lango viršuje paspauskite "RUN" mygtuką.
>8. Smagaus naudojimo!!!
