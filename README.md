# TP2_Synthesis_Moulin_Flandin

L'objectif de ce TP et de créer un échange client-serveur (pour échanger des fichiers) via le protocole TFTP (niveau 4 dans le modèle TCP/IP). Nous utiliserons donc les RFC qui sont des documents numérotées contenant des informations sur la manière d'utiliser le protocole TFTP.  
L'objectif sera de gérer deux commandes :  
- gettftp host file  
- puttftp host file


---
## Question 1 


On passe les informations de la ligne de commande dans la chaine de caractère argv. Les informations extraites sont le nom du serveur ainsi que le nom du fichier à manipuler.  


---
## Question 2  

On utilise un pointeur vers une structure addrinfo permettant de forcer l'IPV4 ainsi que de prioriser TFTP sur UDP. Le champ ai_family contient le type d'adresse, ai_socktype contient le type de socket, soit le mode de fonctionnement que l'on peut utiliser, et ai_protocol contient le protocole IPV4 que l'on veut utiliser pour établir une connexion avec le serveur. On configure alors getaddrinfo qui permet d'obtenir la liste des adresse IP et port du serveur. 


---  
## Question 3

On crée la liaison entre le client et le serveur (socket) selon les informations de requêtes obtenues à la Q1 (ai_family, ai_socktype, ai_protocol).


Bien entendu, on teste la valeur de retour de la fonction (-1 si erreurs) et on renvoie une erreur si besoin.
