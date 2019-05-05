#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "main_window.h"



int main(int argc, char **argv)
{
    GtkWidget *win, *vbox, *text, *sep, *image, *bar;

    gtk_init(&argc, &argv);

    win =   create_window("Verschiedene Anzeigeelemente", 400, 400);
    vbox =  gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    text =  gtk_label_new("Cute chick with hairy pussy");
            gtk_label_set_justify(GTK_LABEL(text), GTK_JUSTIFY_FILL);
    sep =   gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    image = gtk_image_new_from_file("pic.jpg");
    bar =   gtk_statusbar_new();
            gtk_statusbar_push(GTK_STATUSBAR(bar), 0 , "Informationen der aktellen Aktionen");

    gtk_container_add(GTK_CONTAINER(win), vbox);
    gtk_box_pack_start(GTK_BOX(vbox), text, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), sep, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), image, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), bar, FALSE, FALSE, 0);

    gtk_widget_show_all(win);
    gtk_main();

    puts("Die GTK-Hauptschleife wurde beendet!");
    return EXIT_SUCCESS;
}

