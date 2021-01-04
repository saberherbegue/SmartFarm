#include <gtk/gtk.h>

typedef struct {
	char type[30];
	char marque[30];
	char puissance[30];
	char annee[30];
	char matricule[30];
 }equipement;
equipement e,m;


int ajouter_equipement(equipement e);
void supprimer_equipement(char matricule[30]);
void modifier_equipement(equipement e);
void  afficher_equipement(GtkWidget *treeview);
