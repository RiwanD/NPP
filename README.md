# NP&P
NIRYO Pick & Place

    Résumé:
    Reconnaissance, préhension et déplacement d'une pièce, par le bras robotisé NIRYO, choisie par l'utilisateur depuis une interface

Participants : 
Jason CHAZELAS - SEE4
Samuel GUIRLET - SEE4
Audric Moussaoui - MT4
Thomas LEMAIRE - SEE4
Pierre Bouillot - MT4
Thomas COSTA - MT4
Riwan D'HERVAIS - MT4

Toutes les tâches seront implémentées grâce à ROS

    Spécifications technique :
    Matériel à utiliser 
        1 x Bras NYRIO (avec une pince pour prendre les objets - grppier large)
        1 x Support pour le bras
        1 x Caméra : RGB-D D435
        1 x Poignet avec support caméra
        1 x Câble USB
        1 x Raspberry Pi (si non compris avec le bras)
    Tâches à faire
        Robot:
            Paramétrage du robot
            Contrôle du robot
            Déplacement du robot d'un point A à un point B
            Attraper un objet avec la pince
            Déplacer l'objet et le déposer ailleurs
        Vision:
            Mettre en place un système de capture d'image
            Créer/Utiliser une bibliothèque OpenCV pour identifier les objets à prendre sur l'image capturée
            Evaluer la distance entre le bras et l'objet
            Associer la vision et le mouvement du robot
        IHM:
            Créer une interface Qt pour l'utilisateur
            Créer une liste d'objets sélectionnables
            Associer l'interface à la bibliothèque
        

Déjà fait : 
        Expliciter et mettre en forme nos attentes
        Formulation du nom du projet
        Définition des missions du robot
        Définition des besoins matériels
        Réalisation d'une bete à corne et d'un diragramme pieuvre 


Jason CHAZELAS - Simulation du Nyrio avec ROS 
Samuel GUIRLET - Lier la caméra avec ROS
Audric Moussaoui - Interface d'utilisation du robot
Thomas LEMAIRE - Vision avec la caméra et ROS
Pierre Bouillot - Interfacer toutes les composantes avec ROS
Thomas COSTA - Interfacer toutes les composantes avec ROS
Riwan D'HERVAIS - Interfacer toutes les composantes avec ROS
