// 野蠻人 一般設定 By Tmr 2002/05/08

// prototypes
mixed do_chat(mixed chat);
varargs string name(int raw);
void kill_ob(object ob);
varargs int is_fighting(object ob);

int accept_fight(object ob)
{
        if( is_fighting() ) {
                return 0;
        }
        do_chat( name() + "眼露兇光的撲了過來！！\n");
        kill_ob(ob);
        return 1;
}

void accept_kill(object ob)
{
        do_chat( name() + "狂吼一聲，眼露兇光的撲了過來！！\n");
}

