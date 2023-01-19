Confusion++, progetto "Battaglia navale"

Scelte implementative:

	- Il codice utilizza la programmazione orientata agli oggetti per creare diverse classi che rappresentano
	  i vari elementi del gioco, come le navi, le griglie, e i giocatori.

	- Viene utilizzata anche la programmazione generica per creare container di navi con l'uso di unique_ptr, per garantire 
	  una corretta gestione della memoria durante il gioco.

	- Vengono anche utilizzate delle forward declarations tra Ship e DefenseGrid in modo tale da evitare circular dependencies, cosa 
	  che comunque non influenza negativamente il codice, in quanto per come sono state progettate le due classi il funzionamento 
	  di una dipende dall'utilizzo dell'altra e viceversa.

Design:

	- Il design utilizzato per il progetto segue il modello di "model-view-controller" (MVC), in cui il modello rappresenta
	  i dati del gioco, la vista rappresenta come i dati vengono visualizzati dal giocatore e il controller gestisce la logica 
	  del gioco e la comunicazione tra il modello e la vista.

Gestione delle eccezioni:

	- Vengono utilizzati gli standard di C++ per gestire gli errori, come throw e catch. Ad esempio, vengono lanciate eccezioni 
	  quando si tenta di posizionare una nave fuori dai limiti della griglia o se si tenta di posizionare una nave che si sovrappone 
	  ad un'altra, che sono poi gestite opportunamente per restituire un messaggio di errore al giocatore.
	  Viene anche utilizzata una funzione di regex per garantire che l'utente inserisca sempre e solo comandi validi.

Stampe:
	
	- Per differenziare i piazzamenti e i turni tra giocatore 1 e giocatore 2, vengono inseriti dei numeri (1 e 2) prima di ogni
 	  azione eseguita, permettendo anche di effetturare un replay efficiente delle partite.

	- Il replay stampa all'inizio le griglie di entrambi i giocatori con i posizionamenti delle navi, e in seguito tutte le azioni
	  della partita inclusi comando effettuato e da quale giocatore e le rispettive griglie.
	
	- Non è stato possibile fare in modo che le due griglie fossero visualizzate una accanto all'altra a causa di come le classi che 
	  le rappresentano sono state progettate.
	
	- Se viene effettuata la stampa di un replay su file in un sistema operativo Windows esso non verrà visualizzato correttamente: 
	  dato che vengono utilizzati caratteri unicode per la visualizzazione della griglia durante la partita, tali caratteri non vengono 
	  codificati in maniera giustaal momento della scrittura su file; l'indentazione rimane comunque la stessa, perciò il file risulta 
	  comunque relativamente leggibile. Tale problema non viene riscontrato su sistema operativo Linux.  
	