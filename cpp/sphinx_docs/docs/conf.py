# -*- coding: utf-8 -*-
extensions = ['breathe']

# The master toctree document.
master_doc = 'index'

# html_theme = 'sphinxdoc'
html_theme = 'sphinx_rtd_theme'

breathe_projects = { "SphinxDocsDemo": "doxy_xml/" }
breathe_default_project = "SphinxDocsDemo"

