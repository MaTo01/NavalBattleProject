# NavalBattleProject

Progettare un programma in C++ che implementi una versione avanzata del gioco "Battaglia Navale". Le regole non sono quelle classiche, perciò prestare attenzione alla descrizione del gioco

<h2><strong>Regole del gioco</strong></h2>
<p>Ogni giocatore possiede due griglie di gioco composte da 12x12 caselle. Una <strong>griglia di difesa</strong>
che serve per posizionare le proprie unità navali, e una <strong>griglia di attacco</strong> che serve per tenere
traccia dei colpi alle unità avversarie andati a segno (X) o meno (O). Inoltre ogni giocatore
possiede 8 unità di tre tipologie diverse. I tre tipi di unità sono: corazzata (C), nave di supporto
(S), sottomarino di esplorazione (E).</p>
<p align = center ><img src = "https://i.postimg.cc/rmXSTjfC/Immagine-2022-12-26-131133.jpg"></p>

<h2><strong>Unità navali</strong></h2>
<p>Tutte le unità navali possono compiere un'<strong>azione</strong> che però si differenzia a seconda del tipo di
unità. Inoltre ogni unità ha una <strong>dimensione specifica</strong> che equivale anche alla sua corazza
iniziale. Quando tutte le caselle che un’unità occupa vengono colpite, l’unità è da considerarsi
affondata. Corazza e dimensione sono inizialmente equivalenti. Man mano che l’unità viene
colpita la corazza diminuisce mentre la dimensione rimane la stessa.</p>
<p align = center ><img src = "https://i.postimg.cc/wv1TWYXw/Immagine-2022-12-26-131207.jpg"></p>

<p>Le <strong>azioni</strong> che le diverse unità navali possono eseguire sono riportate di seguito:
<ul>
<li><strong>Fuoco</strong>🔥: la <strong>corazzata</strong> fa fuoco su determinate coordinate. Il colpo va a segno se la casella
colpita è occupata da un’unità avversaria. Se la corazza dell’unità bersaglio raggiunge 0
(tutte le caselle in cui l’unità è presente sono state colpite), l’unità bersaglio viene
affondata</li>
<li><strong>Muovi e ripara</strong>🔨: la <strong>nave di supporto</strong> si sposta sulle coordinate ricevute. Ovviamente la
casella non deve essere già occupata. Una volta che si è mossa, dà supporto a tutte le
unità del giocatore presenti in un’area 3x3 considerando come centro la stessa nave di
supporto. Le unità in quest’area verranno completamente riparate (cioè la corazza ritorna
al valore iniziale). Basta che una sola casella sia all’interno dell’area perché tutta l’unità
riceva supporto. La nave che dà supporto non può beneficiare delle sue stesse
riparazioni (quindi per essere riparata deve beneficiare dell’aiuto di un’altra nave di
supporto).</li>
<li><strong>Muovi e cerca</strong>🔎: il <strong>sottomarino</strong> si sposta sulle coordinate ricevute. Ovviamente la casella
non deve essere già occupata. Una volta che si è mosso, lancia un impulso sonar che
svela se ci sono unità avversarie in un’area 5x5 considerando come centro il sottomarino
stesso. Le caselle in cui ci sono unità avversarie (o parti di unità avversarie) vengono
riportate sulla griglia di attacco con il carattere Y.</li>
</ul>

<strong>ATTENZIONE:</strong> Il movimento è relativo alla casella centrale dell’unità. Ogni movimento deve essere valido, cioè
l’unità dopo il movimento deve essere interamente all’interno della griglia e non può sovrapporsi
con altre unità del giocatore. Non esiste rotazione, le unità traslano in modo rigido sulla griglia.</p>

<h2><strong>Giocatori e turni</strong></h2>
<p>Esistono sempre e solo due giocatori. Uno dei due giocatori può essere umano. All’inizio del
gioco, tutti i giocatori posizionano le unità sulla propria griglia di difesa. Il programma decide in
modo casuale il giocatore che inizia il gioco. Nel proprio turno, il giocatore deve far compiere
un'<strong>azione</strong> a solo una delle proprie unità. Una volta che l’<strong>azione</strong> è compiuta, il turno passa
all’altro giocatore.</p>
<p><strong>ATTENZIONE</strong>: Non viene richiesto di implementare degli algoritmi intelligenti per il computer. Nel turno, il
giocatore "computer" seleziona in modo casuale una delle proprie unità e ne esegue l’azione.</p>

<h2><strong>Comandi di gioco</strong></h2>
<p>Ogni giocatore fa eseguire l’<strong>azione</strong> a una delle proprie unità, utilizzando un comando con la
seguente sintassi:</p>
<p>XYOrigin XYTarget</p>
<ul>
<li><strong>XYOrigin</strong> corrispondono alle coordinate dell’unità che deve compiere l’azione (le coordinate
che identificano un’unità sono quelle della casella centrale).</li>
<li><strong>XYTarget</strong> corrispondono alle
coordinate che sono target dell’azione dell’unità. In caso di corazzata corrispondono alla casella
target di fuoco; nel caso di nave di supporto e sottomarini di esplorazione corrispondo alla
casella di arrivo dello spostamento.</li>
</ul>
<p>Con un comando speciale (<strong>AA AA</strong>) è possibile cancellare gli avvistamenti sonar (Carattere Y)
nella griglia di attacco (in quanto le unità si sono mosse, e gli avvistamenti possono non essere
aggiornati). Questo comando non usa la mossa del turno.</p>

<h2><strong>Posizionamento iniziale delle unità navali</strong></h2>
<p>Il posizionamento iniziale delle unità navali viene effettuato a inizio partita. In questa fase di
gioco, il programma chiede al giocatore di fornire le coordinate della prua e della poppa di
ognuna delle proprie unità. Le unità possono essere disposte solo in senso orizzontale o
verticale e non possono sovrapporsi.</p>

<h2><strong>Visualizzazione</strong></h2>
<p>Nel caso di partita con un giocatore, è possibile richiedere al programma la visualizzazione
delle griglie di difesa e di attacco usando un comando speciale:</p>

<p><strong>XX XX</strong></p>

<p>La visualizzazione avviene stampando un carattere per ciascuna unità navale nella griglia di
difesa e per ciascun colpo effettuato e per le rilevazioni sonar nella griglia di attacco.</p>

<p align = center ><img src = "https://i.postimg.cc/NjC3d9dw/Immagine-2022-12-26-131231.jpg"></p>

<p>Se non è presente nessuna unità o nessuno colpo effettuato o nessuna rilevazione, è stampato
uno spazio. Le caselle corrispondenti a parti di unità colpite sono segnate con lettera minuscola.</p>

<h2><strong>Partite</strong></h2>
<p>Le partite sono di due tipi</p>
<ul>
<li>partite <strong>computer</strong> vs <strong>computer</strong>;</li>
<li>partite <strong>computer</strong> vs <strong>giocatore</strong>;</li>
</ul>
<p>Il programma deve gestirle entrambe. Nel caso di partite tra due computer, va fissato un
numero massimo di turni, oltre il quale la partita è considerata nulla. Durante ogni partita deve
essere effettuato un log su file, che elenca tutti i comandi inviati, in ordine. Il programma deve
essere in grado di effettuare il replay di una partita dato un log su file, che deve essere un file
testuale con estensione .txt.</p>

<h2><strong>Replay</strong></h2>
<p>Il progetto deve essere corredato di un modulo (costituito da un eseguibile a parte, vedi
prossimo punto) per il replay della partita, effettuato leggendo il relativo log. Il replay è realizzato
stampando le due griglie di gioco per ogni turno. La stampa avviene a video, con un’opportuna
pausa (es., 1 secondo) tra una turno e il successivo, oppure su file – in questo caso la scrittura
avviene senza pause.</p>

<h2><strong>Eseguibili</strong></h2>
<p>Il progetto deve generare due eseguibili</p>
<ul>
<li>L’eseguibile del gioco, chiamato “battaglia_navale”, che deve gestire gli argomenti da riga
di comando, secondo il seguente schema:
  <ul>
  <li>argomento pc: partita giocatore vs. computer (p sta per player, c per computer);</li>
  <li>argomento cc: partita computer vs. computer;</li>
  </ul>
</li>
<li>L’eseguibile per il replay, chiamato “replay”, che accetta gli argomenti da riga di comando
secondo il seguente schema:
  <ul>
  <li>argomento v [nome_file_log]: stampa a video il replay del file di log indicato;</li>
  <li>argomento f [nome_file_log] [nome_file_output_replay]: scrive su file il replay del
      file di log indicato.</li>
  </ul>
</li>
</ul>

<h2><strong>Consegna</strong></h2>
<p>Il compito deve essere consegnato su Moodle (consegna di gruppo come per la prova
intermedia), caricando un archivio che include una sola directory contenente:</p>
<ul>
<li>Il codice sorgente (eventualmente organizzato in sottodirectory).</li>
<li>Il file CMakeLists.txt necessario alla compilazione (uno solo e posto nella directory
principale del progetto).</li>
<li>Un file di log di una partita computer vs. computer e un file di log di una partita computer
vs giocatore.</li>
<li>Un file readme.txt in cui riportate eventuali note che volete comunicare in fase di
correzione. Questo file non è la documentazione, che deve essere inserita sotto forma di
commenti nel codice, ma un elenco di note aggiuntive per chi corregge, per esempio
problemi riscontrati e non risolti.</li>
</ul>
<p>L'archivio non deve contenere l'eseguibile, perché il sorgente sarà compilato in fase di
correzione. Il sistema CMake deve compilare con le opzioni di ottimizzazione attivate (-O2).</p>

<br><h1><strong>FAQ</strong></h1>
<h3><strong>Q1. Cosa succede alla griglia d'attacco se una nave si muove?</strong></h3>
<p>A1. Il movimento delle navi rende la griglia d'attacco non più aggiornata. Questo vale sia per i
colpi andati a segno che per quelli a vuoto. In fase di visualizzazione, potete decidere di
implementare dei comandi aggiuntivi per il reset della griglia d'attacco. Ad esempio, digitando il
comando BB BB possono essere cancellati tutti i caratteri relativi a colpi andati a segno (X),
oppure con il comando CC CC si possono cancellare tutti i colpi a vuoto (O). Lasciamo a voi
decidere come gestire questi comandi aggiuntivi.</p>
<h3><strong>Q2. Se una nave è colpita si può muovere? Se si muove, cosa succede sulla mappa di chi
ha colpito?</strong></h3>
<p>A2. Sì, una nave colpita si può muovere. In questo caso, la griglia d'attacco di chi ha sferrato il
colpo non è più aggiornata (vedi sopra). La griglia può essere aggiornata con nuove rilevazioni
radar.</p>
<h3><strong>Q3. Due navi di supporto che si curano l'un l'altra creano uno stallo che va all'infinito.</strong></h3>
<p>A3. Sì, può succedere. Per questo è previsto un numero massimo di turni dopo il quale la
partita è patta.</p>
<h3><strong>Q4. Nel caso una nave sia affondata, un'altra può passare sopra?</strong></h3>
<p>A4. Sì: una nave affondata è rimossa completamente dalla griglia di difesa.</p>
<h3><strong>Q5. La partita è da considerarsi vinta quando tutte le corazzate dell'avversario sono state
distrutte? Perché in caso contrario il giocatore senza corazzate non potrebbe più
sparare, ne curarsi le corazzate affondate.</strong></h3>
<p>A5. Sì, la partita è da considerarsi vinta quando tutte le unità dell'avversario sono state
affondate. Quindi la partita continua anche nel caso in cui un giocatore rimane senza corazzate.</p>
<h3><strong>Q6. Nel caso di partita giocatore vs computer, come teniamo il conto di cosa il computer
ci colpisce? Ad esempio come facciamo a sapere che una corazzata è stata distrutta?</strong></h3>
<p>A6. Potete tener conto dei colpi ricevuti sulle vostre unità, utilizzando i caratteri minuscoli.
Quindi una corazzata identificata da [c c C C C] ha due caselle colpite e tre sane (corazza=3).
Quando una nave viene affondata deve essere rimossa dalla griglia difensiva del giocatore.</p>
<h3><strong>Q7. Nello stampare la griglia, dobbiamo mettere dei caratteri di separazione tra una cella
e l'altra (ad esempio '|' ) o solo degli spazi o niente?</strong></h3>
<p>A7. Lasciamo a voi decidere come gestire i caratteri di separazione fra una cella e l'altra.</p>
<h3><strong>Q8. Durante il turno del computer, scelta un'unità casualmente, anche l'azione della
suddetta unità deve essere random? Per esempio qualora il computer avesse un
avvistamento (Y) nella posizione (X,Y), e potesse attaccare con la corazzata, dovrebbe
preferire come punto da colpire il punto (X,Y)?</strong></h3>
<p>A8. La consegna non richiede di implementare algoritmi intelligenti che gestiscano il
comportamento del computer. Tuttavia se volete potete farlo.</p>
<h3><strong>Q9. Quando si colpisce un'unità nemica, il turno cambia o come nella normale battaglia
navale esso rimane del giocatore che ha attaccato?</strong></h3>
<p>A9. Anche se si colpisce un’unità nemica, il turno passa all’altro giocatore.</p>
<h3><strong>Q10. Quando si colpisce un'unità nemica, nella griglia di attacco viene messo il carattere
"X" nella posizione colpita; qualora la nave nemica si sposti, il carattere "X" deve
rimanere (e quindi può essere tolto con un sommergibile) o deve diventare " "?</strong></h3>
<p>A10. La griglia d’attacco può essere aggiornata solo tramite il rilevamento sonar del sottomarino
o può essere resettata completamente dal giocatore tramite un comando speciale che potete
implementare (ad esempio digitando BB BB). Vedi risposta A1.</p>
<h3><strong>Q11. Il numero massimo di turni vale anche per partite giocatore vs. computer?</strong></h3>
<p>A11. Sì, potete decidere di definire un numero massimo di turni anche nel caso di partita
giocatore vs. computer.</p>
<h3><strong>Q12. I comandi non validi (ad esempio perché la sintassi è sbagliata) e i comandi speciali
(XX XX, AA AA, BB BB, CC CC) devono essere inclusi nel log?</strong></h3>
<p>A12. No, solo i comandi validi (esclusi quelli speciali) devono essere inclusi nel log.</p>
<h3><strong>Q13. Il replay è realizzato stampando le due griglie di gioco per ogni turno. Si intendono
le griglie di difesa di ciascuno dei due giocatori?</strong></h3>
<p>A13. No, si intende la griglia di difesa e di attacco del giocatore attivo in ciascun turno.</p>
<h3><strong>Q14. Nel caso una nave con un segmento già colpito si muova e venga rilevata da un
sonar nella nuova posizione, il segmento colpito, nel campo d'attacco del giocatore che
ha lanciato il sonar, viene visualizzato con una 'X' (facendo capire quindi che la nave
rilevata era quella colpita in precedenza) o viene visualizzato con una 'Y' (come se fosse
una normale rilevazione del sonar)?</strong></h3>
<p>A14. In questo caso la nave rilevata dal sonar verrà visualizzata con il segmento colpito. In altre
parole, il sonar ritorna la posizione e lo stato corrente delle nave.</p>
