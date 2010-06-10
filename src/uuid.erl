-module(uuid).
-export([generate/0]).
-on_load(load_nifs/0).

load_nifs() ->
  File = filename:join([filename:dirname(code:which(?MODULE)), "uuid"]),
  erlang:load_nif(File, 0).

generate() ->
  nif_error(?LINE).    

nif_error(Line) ->
  exit({nif_not_loaded,module,?MODULE,line,Line}).
