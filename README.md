-->IMPORTANT: A fost nevoie sa fac niste schimbari in checker pentru ca fisierele de output erau identice cu cele de la rezultate, insa nu obtineam "passed". Asa ca --> la linia 63 din checker am sters "-Z -q" de la diff. De aceea am adaugat si checker-ul in arhiva.
Nu stiu daca trebuia, dar in urma acestui lucru, testele au mers foarte bine.

-->Am implementat cu succes:
-cerinta 1
-cerinta 2
-cerinta 3
-cerinta 4

-->Pentru implementare am folosit liste simplu inlantuite, pentru prima si a doua cerinta; cozi si stive pentru a treia cerinta si arbore binar de cautare (BST) pentru a patra cerinta. 

-->Consider ca implementarea mea este una buna insa cred ca ar fi metode si mai eficiente de implementare a acesteia. 

--> Descrierea solutiei: Pentru inceput, am citit datele de intrare, iar odata cu citirea am calculat si punctajul total al echipelor si am adaugat aceste informatii intr-o lista simplu inlantuita. Pentru cerinta a doua, am creat functii care calculeaza numarul de echipe dintr-o lista si scorul minim al echipelor din lista. Cat timp nu am ajuns la cel mai mare numar n care este si putere a lui 2, am sters echipa cu cel mai mic scor. La cerinta 3 am intampinat niste dificultati deoarece in urma parcurgerii atat a cozii cat si a stivei, acestea deveneau nule, asa ca am creat niste copii pe care le-am sacrificat doar pentru afisare. Am creat o noua stiva cu elementele inversate din stiva de castigatori pentru a putea popula ulterior coada de meciuri in ordinea ceruta. Totodata, am creat si lista cu echipele de pe primele 8 locuri pentru a o putea utiliza la cerinta a4-a. La cerinta a4-a am construit arborele binar de cautare conform cerintelor cerute si l-am parcurs in inordine pentru a afisa descrescator echipele, impreuna cu punctajele acestora.
