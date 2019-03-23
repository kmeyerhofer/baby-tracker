baby_tracker_sources = [
  'main.c',
  'baby-tracker-window.c',
]

# libhandydir = include_directories('/home/kurt/coding/GNOME/libhandy')
#libhandydep = delare_dependency(include_directories : libhandydir)
# Taken from http://bytesgnomeschozo.blogspot.com/2019/01/my-name-is-handy-lib-handy.html
libhandy_dep = dependency('libhandy-0.0', required: false)
if not libhandy_dep.found()
	libhandy = subproject(
		'libhandy',
		install: false,
		default_options: [
			'examples=false',
			'package_subdir=baby-tracker',
			'tests=false',
		]
	)
	libhandy_dep = libhandy.get_variable('libhandy_dep')
endif

baby_tracker_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
  #dependency('libhandy-0.0', fallback : ['libhandy-0.0', 'libhandydep'])
  libhandy_dep
]

gnome = import('gnome')

baby_tracker_sources += gnome.compile_resources('baby-tracker-resources',
  'baby-tracker.gresource.xml',
  c_name: 'baby_tracker'
)

executable('baby-tracker', baby_tracker_sources,
  dependencies: baby_tracker_deps,
  install: true,
)