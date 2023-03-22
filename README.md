Program PreStressedStudent powstał w ramach realizacji pracy dyplomowej, w której zakresie znajduje się
stworzenie algorytmu obliczeniowego dla dźwigarów strunobetonowych w zakresie SGN i SGU. W zamyśle autorki była
przede wszystkim intuicyjność tego narzędzia połączona z jak najszerszym zakresem obliczeniowym programu.
Do napisania programu posłużono się językiem programowania C++ oraz wykorzystano biblioteki QT żeby utworzyć
interfejs graficzny (https://www.qt.io/). 
Narzędzie, w którym wszystko skompilowano to QTCreator (https://pl.wikipedia.org/wiki/Qt_Creator).
Program bazuje na uproszczonej metodzie wymiarowania dźwigarów strunobetonowych zawartej w PN-EN 1992-1-1
Eurokod 2: Projektowanie konstrukcji z betonu, część 1-1: Reguły ogólne i reguły dla budynków .
Weryfikację otrzymanych wyników przeprowadzono na dwa sposoby: na podstawie ręcznych obliczeń dla dwóch dźwigarów
oraz osobnego algorytmu obliczeniowego stworzonego w programie Excel.
Program pozwala m.in. na:
- sprawdzenie czy dobrany przekrój spełnia warunek smukłości,
- ile cięgien będzie potrzebnych do przeniesienia momentu zginającego działającego na przekrój,
- jakie otuliny należy przyjąć aby zapewnić ochronę stali przy projektowanej klasie konstrukcji i agresywności środowiska,
- wyliczenie charakterystyk geometrycznych dla przekroju z uwzględnieniem betonu i stali,
- obliczenie współczynnika pełzania,
- obliczenia strat sprężania powstałych od czynników reologicznych (strat opóźnionych) oraz strat doraźnych,
- obliczenia ugięcia elementu oraz momentu krytycznego w celu weryfikacji, czy element się zarysuje.
Do największych zalet programu należy skrócenie czasu pracy podczas wymiarowania przekrojów strunobetonowych i
możliwość wyboru szeregu danych takich jak klasa ekspozycji, klasa przekroju, klasa relaksacji stali, przyjęcie sprężania
prętami, drutami lub splotami itd. Dzięki temu narzędzie jest uniwersalne.
