#include <gtk/gtk.h>
#include <stdio.h>



////////////////////////////////////////////////////////////// kleine_callback
void kleine_callback(GtkWidget *w, gpointer d)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Hallo, Welt!");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

////////////////////////////////////////////////////////////// tag_auswaehlen
void tag_auswaehlen(GtkWidget *l, gpointer c)
{
    guint jahr, monat, tag;
    char text[32];
    GtkLabel *label = GTK_LABEL(l);
    GtkCalendar *calendar = GTK_CALENDAR(c);
    gtk_calendar_get_date(calendar, &jahr, &monat, &tag);
    snprintf(text, 32, "Ausgewählt: %02d.%02d.%d", tag, monat, jahr);
    gtk_label_set_text(label, text);
}

