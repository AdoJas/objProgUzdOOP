# ***Klasės ir struktūros***

## Kompiuterio komponentai naudoti testavimo metu 

|   Komponentas  |                   Pavadinimas                       |                      
|:--------------:|:---------------------------------------------------:|
|     **CPU**    |            `AMD Ryzen 5 3600 6-core`              |
|     **GPU**    |`G.Skill Trident Z RGB DDR4 16GB (2x8GB) 3200MHz`  |
|     **SSD**    |           `Samsung SSD 970 EVO Plus, 500GB`       |


# Turinys
- [x] [Projekto dokumentacija - Doxygen](#projekto-dokumentacija)
- [x] [Kelios Vector klases funkcijos](#kelios-vector-klases-funkcijos)
- [x] [Testavimas - GoogleTest Vector klase](#testavimas)
- [x] [Ka daro programa?](#ka-daro-programa)
- [x] [Kaip pasinaudoti kodu? (Windows ir macOS)](#kaip-pasinaudoti-kodu-windows-ir-macos)
# Projekto dokumentacija
## Doxygen
> Projekto dokumentacija galite perzvelgti naudodami savo IDE arba overleaf.com online Latex compiliatoriu, tereikia ikelti latex failo .zip rinkini.

## Testavimas 
> 1. Testavimas buvo darytas su Googel Test Unit testu testavimo frameworku.
> 2. Nuoroda i Google Test -> https://github.com/google/googletest/releases
> 3. Buvo testuojama Vector class'e, a.k.a. Vector klases metodai

## Kelios Vector klases funkcijos
> 1. `void PushBack(reference object)` - prideda nauja elementa i Vector konteineri.
> 2. `void PopBack()` - istrina paskutini elementa is Vector konteinerio.
> 3. `void Insert(size_type index, reference object)` - iterpia nauja elementa i Vector konteineri pagal nurodyta index'a.
> 4. `void Erase(size_type index)` - istrina elementa is Vector konteinerio pagal nurodyta index'a.
> 5. `void Resize(size_type n)` - pakeicia Vector konteinerio dydi i n.
### Funkciju kodas issamiau
#### 1. `void PushBack(reference object)`
```
    void PushBack(reference object) {
    if (size == capacity) {
    Reserve(capacity == 0 ? 1 : capacity * 2);
    }
    elements[size] = object;
    size++;
    }
```
1. `if (size == capacity)` - tikrina ar Vector konteineris pilnas.
2. `Reserve(capacity == 0 ? 1 : capacity * 2);` - jei konteineris pilnas, tai padvigubinamas jo dydis.
3. `elements[size] = object;` - prideda nauja elementa i Vector konteineri.
4. `size++;` - padidina Vector konteinerio dydi vienetu.
5. `}` - uzbaigia funkcija.

#### 2. `void PopBack()`
```
    void PopBack() {
    if (size == 0) {
    throw std::out_of_range("Vector is empty");
    }
    size--;
    }
```
1. `if (size == 0)` - tikrina ar Vector konteineris tuscias.
2. `throw std::out_of_range("Vector is empty");` - jei konteineris tuscias, tai ismeta klaida.
3. `size--;` - istrina paskutini elementa is Vector konteinerio.
4. `}` - uzbaigia funkcija.

#### 3. `void Insert(size_type index, reference object)`
```
    void Insert(size_type index, reference object) {
    if (index < 0 || index > size) {
    throw std::out_of_range("Index out of range");
    }
    if (size == capacity) {
    Reserve(capacity == 0 ? 1 : capacity * 2);
    }
    for (size_type i = size; i > index; i--) {
    elements[i] = elements[i - 1];
    }
    elements[index] = object;
    size++;
    }
```
1. `if (index < 0 || index > size)` - tikrina ar nurodytas index'as yra tinkamas.
2. `throw std::out_of_range("Index out of range");` - jei index'as netinkamas, tai ismeta klaida.
3. `if (size == capacity)` - tikrina ar Vector konteineris pilnas.
4. `Reserve(capacity == 0 ? 1 : capacity * 2);` - jei konteineris pilnas, tai padvigubinamas jo dydis.
5. `for (size_type i = size; i > index; i--)` - ciklas, kuris perstumia elementus i desine.
6. `elements[i] = elements[i - 1];` - perstumia elementus i desine.
7. `elements[index] = object;` - iterpia nauja elementa i Vector konteineri pagal nurodyta index'a.
8. `size++;` - padidina Vector konteinerio dydi vienetu.
9. `}` - uzbaigia funkcija.

#### 4. `void Erase(size_type index)`
```
    void Erase(size_type index) {
    if (index < 0 || index >= size) {
    throw std::out_of_range("Index out of range");
    }
    for (size_type i = index; i < size - 1; i++) {
    elements[i] = elements[i + 1];
    }
    size--;
    }
```
1. `if (index < 0 || index >= size)` - tikrina ar nurodytas index'as yra tinkamas.
2. `throw std::out_of_range("Index out of range");` - jei index'as netinkamas, tai ismeta klaida.
3. `for (size_type i = index; i < size - 1; i++)` - ciklas, kuris perstumia elementus i kaire.
4. `elements[i] = elements[i + 1];` - perstumia elementus i kaire.
5. `size--;` - istrina elementa is Vector konteinerio pagal nurodyta index'a.
6. `}` - uzbaigia funkcija.

#### 5.  `void Resize(size_type n)` 
```
    void Resize(size_type n) {
    if (n < 0) {
    throw std::out_of_range("Size out of range");
    }
    if (n > size) {
    if (n > capacity) {
    Reserve(n);
    }
    for (size_type i = size; i < n; i++) {
    elements[i] = T();
    }
    }
    size = n;
    }
```
1. `if (n < 0)` - tikrina ar n yra teigiamas skaicius.
2. `throw std::out_of_range("Size out of range");` - jei n yra neigiamas skaicius, tai ismeta klaida.
3. `if (n > size)` - tikrina ar n yra didesnis uz size.
4. `if (n > capacity)` - tikrina ar n didesnis uz capacity.
5. `Reserve(n);` - jei n didesnis uz capacity, tai padvigubinamas jo dydis.
6. `for (size_type i = size; i < n; i++)` - ciklas, kuris prideda naujus elementus i Vector konteineri.
7. `elements[i] = T();` - prideda naujus elementus i Vector konteineri.
8. `size = n;` - pakeicia Vector konteinerio dydi i n.
9. `}` - uzbaigia funkcija.


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
