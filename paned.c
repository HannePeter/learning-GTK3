#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "main_window.h"

#define NBOOK   6
#define BUTTONS 4
#define BUF     35



int main(int argc, char **argv)
{
    GtkWidget *win, *vpan, *hpan,
              *nbook, *nbook_content[NBOOK], *nbook_titel[NBOOK],
              *vbutbox, *hbutbox, *vbuttons[BUTTONS], *hbuttons[BUTTONS];
    char buf[BUF];


    gtk_init(&argc, &argv);
    
    win =       create_window("Panes", 450, 200);   
    vpan =      gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    hpan =      gtk_paned_new(GTK_ORIENTATION_VERTICAL);
    nbook =     gtk_notebook_new();
                gtk_notebook_popup_enable(GTK_NOTEBOOK(nbook));

                for (int i = 0; i < NBOOK; i++)
                {
                    snprintf(buf, BUF, "Inhalt von GtkNotebook Seite %d", i+1);
                    nbook_content[i] = gtk_label_new(buf);

                    snprintf(buf, BUF, "Seite %d", i+1);
                    nbook_titel[i] = gtk_label_new(buf);

                    gtk_notebook_append_page_menu(GTK_NOTEBOOK(nbook), nbook_content[i], nbook_titel[i], NULL);
                }

    vbutbox =   gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
    hbutbox =   gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    
                for (int i = 0; i < BUTTONS; i++)
                {
                    snprintf(buf, BUF, "(v)Button %d", i+1);
                    vbuttons[i] = gtk_button_new_with_label(buf);
                    gtk_box_pack_start(GTK_BOX(vbutbox), vbuttons[i], FALSE, FALSE, 0);
                    
                    snprintf(buf, BUF, "(h)Button %d", i+1);
                    hbuttons[i] = gtk_button_new_with_label(buf);
                    gtk_box_pack_start(GTK_BOX(hbutbox), hbuttons[i], FALSE, FALSE, 0);
                }


    gtk_paned_add1(GTK_PANED(hpan), vpan);          // add to the top of pane
    gtk_paned_add2(GTK_PANED(hpan), hbutbox);       // add to the bottom of pane
    gtk_paned_add1(GTK_PANED(vpan), vbutbox);       // add left of pane
    gtk_paned_add2(GTK_PANED(vpan), nbook);         // add right of pane
    gtk_container_add(GTK_CONTAINER(win), hpan);


    gtk_widget_show_all(GTK_WIDGET(win));
    gtk_main();

    g_print("Die GTK-Hauptschleife wurde beendet!\n");
    return EXIT_SUCCESS;
}

