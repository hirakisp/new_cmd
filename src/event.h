
#typedef EVENT_ID uint_16;

struct event {
	char *name;
	EVENT_ID id;
}

struct action {
	void *func;
	char *comment;
}

struct state {
	char *name;
	EVENT_ID accept_events_id[];
	struct action entry;
	struct action do;
	struct action exit;
}
