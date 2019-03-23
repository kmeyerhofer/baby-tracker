/* main.c
 *
 * Copyright 2019 Kurt Meyerhofer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib/gi18n.h>

#include "baby-tracker-config.h"
#include "baby-tracker-window.h"

#define HANDY_USE_UNSTABLE_API
#include <handy.h>

/*
GdkPixbuf *create_pixbuf(const gchar * filename)
{
  GdkPixbuf *pixbuf;
  GError *error = NULL;
  pixbuf = gdk_pixbuf_new_from_file(filename, &error);
  if (!pixbuf)
    fprintf(stderr, "%s\n", error->message);
    g_error_free(error);

  return pixbuf;
}
*/

static void
on_activate (GtkApplication *app)
{
	GtkWindow *window;
  GdkPixbuf *icon;

	/* It's good practice to check your parameters at the beginning of the
	 * function. It helps catch errors early and in development instead of
	 * by your users.
	 */
	g_assert (GTK_IS_APPLICATION (app));

	/* Get the current window or create one if necessary. */
	window = gtk_application_get_active_window (app);
	if (window == NULL)
		window = g_object_new (BABY_TRACKER_TYPE_WINDOW,
		                       "application", app,
		                       "default-width", 600,
		                       "default-height", 300,
		                       NULL);

  //gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
  //gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  //icon = create_pixbuf ("/org/gnome/baby-tracker/io.kcmr.baby-tracker.baby-crawling-silhouette.svg");
  //gtk_window_set_icon(GTK_WINDOW(window), icon);

  //g_object_unref(icon);

	/* Ask the window manager/compositor to present the window. */
	gtk_window_present (window);
}

int
main (int   argc,
      char *argv[])
{
	g_autoptr(GtkApplication) app = NULL;
	int ret;

	/* Set up gettext translations */
	bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);

	/*
	 * Create a new GtkApplication. The application manages our main loop,
	 * application windows, integration with the window manager/compositor, and
	 * desktop features such as file opening and single-instance applications.
	 */
	app = gtk_application_new ("io.kcmr.baby-tracker", G_APPLICATION_FLAGS_NONE);

	/*
	 * We connect to the activate signal to create a window when the application
	 * has been lauched. Additionally, this signal notifies us when the user
	 * tries to launch a "second instance" of the application. When they try
	 * to do that, we'll just present any existing window.
	 *
	 * Because we can't pass a pointer to any function type, we have to cast
	 * our "on_activate" function to a GCallback.
	 */
	g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);

	/*
	 * Run the application. This function will block until the applicaiton
	 * exits. Upon return, we have our exit code to return to the shell. (This
	 * is the code you see when you do `echo $?` after running a command in a
	 * terminal.
	 *
	 * Since GtkApplication inherits from GApplication, we use the parent class
	 * method "run". But we need to cast, which is what the "G_APPLICATION()"
	 * macro does.
	 */
	ret = g_application_run (G_APPLICATION (app), argc, argv);

	return ret;
}
