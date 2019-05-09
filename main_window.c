#include <stdio.h>
#include <gtk/gtk.h>



static int delete_event(GtkWidget *window, gpointer data)
{
    GtkWidget *dialog, *label;
    gint result;

    dialog = gtk_dialog_new_with_buttons(   "Sind Sie sicher?",                                 // Dialogbox erzeugen
                                            GTK_WINDOW(window),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            "Ja", GTK_RESPONSE_ACCEPT,
                                            "Nein", GTK_RESPONSE_REJECT,
                                            NULL);
    label = gtk_label_new( "Wollen Sie das Programm wirklich beenden?");                        // Label erzeugen
    gtk_container_add(GTK_CONTAINER(gtk_dialog_get_content_area(GTK_DIALOG(dialog))), label);   // Zusammenpacken

    gtk_widget_show_all(dialog);                                                                // Dialogbox anzeigen

    result = gtk_dialog_run(GTK_DIALOG(dialog));                                                // Auf Eing. warten
    switch (result)                                                                             // Eing. verarbeiten
    {
        case GTK_RESPONSE_ACCEPT:                                                               // 'Ja'
            puts("GTK_RESPONSE_ACCEPT");
            gtk_widget_destroy(dialog);                                                         // Dialogbox beenden
            return FALSE;                                                                       // Anwendung beenden

        case GTK_RESPONSE_REJECT:                                                               // 'Nein'
            puts("GTK_RESPONSE_REJECT");
            gtk_widget_destroy(dialog);                                                         // Dialogbox beenden
            return TRUE;                                                                        // Anwendung nicht beend.

        case GTK_RESPONSE_DELETE_EVENT:                                                         // 'Schließen'
            puts("GTK_RESPONSE_DELETE_EVENT");
            gtk_widget_destroy(dialog);
            return TRUE;

        default:
            puts("Fehler beim Auswerten der Dialogbox");
            return TRUE;
    }
}

void end(GtkWidget *widget, gpointer data)
{
    puts("Und tschues!");
    gtk_main_quit();
}

GtkWidget *create_window(const char *headline, const int width, const int height)
{
    GdkPixbuf *icon;
    GtkWidget *win;

    icon =  gdk_pixbuf_new_from_file("/usr/share/icons/Papirus-Dark/16x16/actions/color-management.svg", NULL);
    win =   gtk_window_new(GTK_WINDOW_TOPLEVEL);
            gtk_window_set_title(GTK_WINDOW(win), headline);
            gtk_window_set_default_size(GTK_WINDOW(win), width, height);
            gtk_window_set_resizable(GTK_WINDOW(win), TRUE);
            gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
            gtk_window_set_icon(GTK_WINDOW(win), icon);

    g_signal_connect(win, "delete-event", G_CALLBACK(delete_event), NULL);
    g_signal_connect(win, "destroy", G_CALLBACK(end), NULL);

    return win;
}

