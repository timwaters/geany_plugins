#include <geanyplugin.h>

GeanyPlugin     *geany_plugin;
GeanyData       *geany_data;
GeanyFunctions  *geany_functions;

PLUGIN_VERSION_CHECK(211)

PLUGIN_SET_INFO("HelloWorld", "Just another tool to say hello world",
                "1.0", "John Doe <john.doe@example.org>");


static GtkWidget *main_menu_item = NULL;

static void item_activate_cb(GtkMenuItem *menuitem, gpointer gdata)
{
    dialogs_show_msgbox(GTK_MESSAGE_INFO, "Hello World");
}

void plugin_init(GeanyData *data)
{
    main_menu_item = gtk_menu_item_new_with_mnemonic("Hello World");
    gtk_widget_show(main_menu_item);
    gtk_container_add(GTK_CONTAINER(geany->main_widgets->tools_menu),
        main_menu_item);
    g_signal_connect(main_menu_item, "activate",
        G_CALLBACK(item_activate_cb), NULL);
}

void plugin_cleanup(void)
{
    gtk_widget_destroy(main_menu_item);
}
