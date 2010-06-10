//return enif_make_string(env, "Hello world!", ERL_NIF_LATIN1);

#include "erl_nif.h"
#include "uuid/uuid.h"

static int load(ErlNifEnv* env, void** priv, ERL_NIF_TERM load_info)
{
	return 0;
}

static int reload(ErlNifEnv* env, void** priv, ERL_NIF_TERM load_info)
{
	return 0;
}

static int upgrade(ErlNifEnv* env, void** priv, void** old_priv, ERL_NIF_TERM load_info)
{
	return 0;
}

static void unload(ErlNifEnv* env, void* priv)
{
	return;
}

static ERL_NIF_TERM generate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  uuid_t new_uuid;
  uuid_generate( new_uuid );

  char str[40];
  uuid_unparse( new_uuid, str );

	return enif_make_string(env, str, ERL_NIF_LATIN1);
}

static ErlNifFunc uuid_funcs[] =
{
	{"generate", 0, generate}
};

ERL_NIF_INIT(uuid, uuid_funcs, load, reload, upgrade, unload)
