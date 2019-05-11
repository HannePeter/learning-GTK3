#include <stdlib.h>
#include <gtk/gtk.h>
#include "main_window.h"
#include "layout_cb.h"



int main (int argc, char **argv)
{
    GtkWidget *win, *layout, *button, *label;

    gtk_init (&argc, &argv);
    
    win     = create_window("Layout", 200, 100);
    layout  = gtk_layout_new(NULL, NULL);
    label   = gtk_label_new("Freies Layout");
    button  = gtk_button_new_with_label("Drück mich!");

    g_signal_connect(button, "clicked", G_CALLBACK(move_button), layout);

    gtk_layout_put(GTK_LAYOUT(layout), label, 10, 10);
    gtk_layout_put(GTK_LAYOUT(layout), button, 10, 50);
    gtk_container_add(GTK_CONTAINER(win), layout);

    gtk_widget_show_all(win);
    gtk_main ();

    g_print("Die GTK-Hauptschleife wurde beendet!\n");
    return EXIT_SUCCESS;
}

