#include <gtk/gtk.h>



static const char *interface = 
    "<interface>"
    "  <object class=\"GtkWindow\" id=\"main-window\">"
    "    <signal name=\"destroy\" handler=\"gtk_main_quit\"/>"
    "    <child>"
    "      <object class=\"GtkButton\" id=\"my-button\">"
    "        <property name=\"label\">Hallo, Welt!</property>"
    "        <signal name=\"clicked\" handler=\"on_button_clicked\"/>"
    "      </object>"
    "    </child>"
    "  </object>"
    "</interface>";

void on_button_clicked(GtkWidget *w, gpointer d)
{
    puts("Hallo, Welt!");
}



int main(int argc, char **argv)
{
    GtkBuilder *builder;
    GError *error = NULL;
    GtkWidget *win;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_string(builder, interface, -1, &error);
    gtk_builder_connect_signals(builder, NULL);
    
    win = GTK_WIDGET(gtk_builder_get_object(builder, "main-window"));

    gtk_widget_show_all(win);
    gtk_main();

    puts("Die GTK-Hauptschleife wurde beendet!\n");
    return EXIT_SUCCESS;
}

