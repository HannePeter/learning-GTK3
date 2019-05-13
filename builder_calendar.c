#include <gtk/gtk.h>
#include <stdio.h>
#include "builder_calendar_cb.h"



int main (int argc, char **argv)
{
    GtkBuilder *builder;
    GError *errors = NULL;
    GtkWidget *win;

    gtk_init(&argc, &argv);
    
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "builder_calendar.xml", &errors);
    gtk_builder_connect_signals(builder, builder);

    win = GTK_WIDGET(gtk_builder_get_object(builder, "hauptfenster"));

    gtk_widget_show_all(win);
    gtk_main();

    puts("Die GTK-Hauptschleife wurde beendet!");
    return EXIT_SUCCESS;
}

