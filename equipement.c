#include<stdio.h>
#include<string.h>
#include "equipement.h"

enum
{
	TYPE,
	MARQUE,
	PUISSANCE,
	ANNEE,
	MATRICULE,
	COLUMNS,
};


//ajouter equipement

int ajouter_equipement(equipement e)
{

FILE *f;
f=fopen("equipement.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s \n",e.type,e.marque,e.puissance,e.annee,e.matricule);
fclose(f);
return 0;
}
}
//afficher equipement

void afficher_equipement(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;

char type[30];
char marque[30];
char puissance[30];
char annee[30];
char matricule[30];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer, "text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" marque",renderer, "text",MARQUE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("puissance",renderer, "text",PUISSANCE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",ANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("matricule",renderer,"text",MATRICULE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

}
	store=gtk_list_store_new(5,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("equipement.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("equipement.txt","a+");
	while(fscanf(f,"%s %s %s %s %s \n",type,marque,puissance,annee,matricule )!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,TYPE,type,MARQUE,marque,PUISSANCE,puissance,ANNEE,annee,MATRICULE,matricule,-1);
	}
	fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

	
}

// supprimer equipement
void supprimer_equipement(char matricule[30])
{
FILE *f,*f1;
f=fopen("equipement.txt","r");
f1=fopen("equipement_tmp.txt","w");
 if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f,"%s %s %s %s %s\n",e.type,e.marque,e.puissance,e.annee,e.matricule )!=EOF)
{
if(strcmp(matricule,e.matricule)!=0)
{
fprintf(f1,"%s %s %s %s %s\n",e.type,e.marque,e.puissance,e.annee,e.matricule);
}
}
fclose(f) ;
fclose(f1);
remove("equipement.txt");
rename("equipement_tmp.txt","equipement.txt");
}
}


//modifier equipement
void modifier_equipement (equipement e)
{

{
FILE *f;
FILE *f2;
f=fopen("equipement.txt","r");
f2=fopen("equipement.txt.tmp","w");
 if ((f!=NULL) && (f2!=NULL))
{
while (fscanf(f,"%s %s %s %s  %s\n",m.type,m.marque,m.puissance,m.annee,m.matricule)!=EOF)
    {
if (strcmp(e.matricule,m.matricule)==0){
   fprintf(f2," %s %s %s %s %s\n",e.type,e.marque,e.puissance,e.annee,e.matricule );
}
else
{    fprintf(f2,"%s %s %s %s  %s\n",m.type,m.marque,m.puissance,m.annee,m.matricule);
   }

}}
fclose(f2);
fclose(f);
remove("equipement.txt");
rename("equipement.txt.tmp","equipement.txt");
}
}






