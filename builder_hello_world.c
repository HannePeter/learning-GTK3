#include <string.h>
#include <gtk/gtk.h>



static const char *interface =
    "<interface>"
    "  <object class=\"GtkWindow\" id=\"main-window\">"
    "    <child>"
    "      <object class=\"GtkLabel\" id=\"my-label\">"
    "        <property name=\"label\">Hallo, Welt!</property>"
    "      </object>"
    "    </child>"
    "  </object>"
    "</interface>";



int main(int argc, char **argv)
{
    GtkBuilder *builder;
    GError *error = NULL;
    GtkWidget *win;

    gtk_init(&argc, &argv);
    
    builder = gtk_builder_new();                                                    // 1 Builder-Objekt erzeugen
    gtk_builder_add_from_string(builder, interface, strlen(interface), &error);     // 2 Interface in Builder laden
    
    win = GTK_WIDGET(gtk_builder_get_object(builder, "main-window"));               // 3 Widgets aus Builder laden

    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);              // 4 Callbackfunktionen einrichten
    
    gtk_widget_show_all(GTK_WIDGET(win));                                           // 5 Fenster anzeigen
    gtk_main();                                                                     // 6 Verarbeitungsschleife von GTK starten

    return EXIT_SUCCESS;
}

