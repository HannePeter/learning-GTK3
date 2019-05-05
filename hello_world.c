#include <stdlib.h>
#include <gtk/gtk.h>

static void on_window_closed(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}



int main(int argc, char **argv)
{
    GtkWidget *window, *label;

    gtk_init (&argc, &argv);                                                    // 1 Umgebung initialisieren
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);                               // 2 Widgets erzeugen
    label = gtk_label_new("Hallo, Welt!");
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_closed), NULL);    // 3 Callbackfunktionen einrichten
    gtk_container_add (GTK_CONTAINER(window), label);                           // 4 Packen
    gtk_widget_show_all(window);                                                // 5 Fenster anzeigen
    gtk_main();                                                                 // 6 Verarbeitungsschleife von GTK starten

    return EXIT_SUCCESS;
}

