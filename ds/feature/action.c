// action.c
// #pragma save_binary
nosave mixed busy, interrupt;
nosave int block;
varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
	if( !new_busy ) return;
	if( !intp(new_busy) && !functionp(new_busy) )
		error("action: Invalid busy action type.\n");
	if(intp(new_busy) && intp(busy))
	{
		if(busy < new_busy) busy = new_busy;
	} else busy = new_busy;
	if( !intp(new_interrupt) && !functionp(new_interrupt) )
		error("action: Invalid busy action interrupt handler type.\n");
	interrupt = new_interrupt;
	set_heart_beat(1);
}
// �]����Ӫ�start_busy()���|�֥[.
// �ڷs�W�@�ӷ|�֥[�� add_busy()
// Luky 05/04/1999
varargs void add_busy(mixed new_busy, mixed new_interrupt)
{
	if( !new_busy ) return;
	if( !intp(new_busy) && !functionp(new_busy) )
		error("action: Invalid busy action type.\n");
	if(intp(new_busy) && intp(busy))
	{
		busy += new_busy;
		// �]�w�W�U��
		if(busy > 5) busy = 5;
		if(busy < 0 ) busy = 0;
	} else busy = new_busy;
	if( !intp(new_interrupt) && !functionp(new_interrupt) )
		error("action: Invalid busy action interrupt handler type.\n");
	interrupt = new_interrupt;
	set_heart_beat(1);

}


varargs void add_block(int new_block)
{
	if( new_block<1 ) return;
	if( !intp(new_block) )
		error("action: Invalid block action type.\n");
	block += new_block;
	// �]�w�W�U��
	if(block > 6) block = 6;
	if(block < 0 ) block = 0;

	set_heart_beat(1);

}

varargs void set_block(int flag)
{
	if(flag>0) block = flag;
		else block =0;

	// �]�w�W�U��
	if(block > 6) block = 6;
	if(block < 0 ) block = 0;

	set_heart_beat(1);

}
nomask mixed query_busy() { return busy; }
nomask int is_busy() { return busy!=0; }
nomask int is_block() { return block!=0; }
// This is called by heart_beat() instead of attack() when a ppl is busy
// doing something else.
void continue_action()
{
	if( intp(busy) && (busy > 0) )
	{
		busy--;
		if(!busy && this_object()->query("env/report_action")) tell_object(this_object(),"[�ʧ@�����C]\n");
	}
	 else 
	if( functionp(busy) )
	{
		if( !evaluate(busy, this_object()) )
		{
			busy = 0;
			interrupt = 0;
		}
	}
	 else
	{
		busy = 0;
		interrupt = 0;
	}
	
	if( block > 0 )
	{
		block--;
	} 
	 else
	if(block < 0) block = 0;
	return;
}

void interrupt_me(object who, string how)
{
	if( !busy ) return;

	if( intp(busy) && intp(interrupt) ) {
		if( busy < interrupt ) busy = 0;
	} else if( functionp(interrupt) ) {
		if( evaluate(interrupt, this_object(), who, how) ) {
			busy = 0;
			interrupt = 0;
		}
	}
}

// This function is for temporary conditions's recovery call_outs, bcz
// such recovery function call_out might be destroyed if some wizard
// destructed the object that is reponsible of it, so we let users launch
// the call_out themself. Thus we can make sure the recovery call_out.
// 
// Because this could cause a serious security problem, so we need highest
// security check here.
// �ץ��}�� skill �M spell �I�s.
// ���Y��ި�/daemon/skill/ �M/daemon/spell/�U������.
// �H�קK�w���W�|�}.
// Luky �ץ� 05/03/1999
int start_call_out(function fun, int delay)
{
	string file;
	if( !previous_object()) return 0;
	file=base_name(previous_object());
	if( geteuid(previous_object()) != ROOT_UID
	     && file[0..13]!="/daemon/skill/"	//�}��skill�I�s (�Ъ`�N�w�����D)
	     && file[0..13]!="/daemon/spell/"	//�}��spell�I�s (�Ъ`�N�w�����D)
	     && userp(this_object())
	     && this_player(1) != this_object()
	     )
		return 0;

	call_out("eval_function", delay, fun);
	return 1;
}

protected void eval_function(function fun) { evaluate(fun); }

// ���קK���ƩI�sskill����delay���, �S�]���禡.
//luky
int skill_active(string mark, function fun, int delay)
{
	string file;
	if( !previous_object()) return 0;
	file=base_name(previous_object());
	if( geteuid(previous_object()) != ROOT_UID
	     && file[0..13]!="/daemon/skill/"	//�}��skill�I�s (�Ъ`�N�w�����D)
	     && file[0..13]!="/daemon/spell/"	//�}��spell�I�s (�Ъ`�N�w�����D)
	     && userp(this_object())
	     && this_player(1) != this_object()
	     )
		return 0;
	if(this_object()->query_temp("skill_active/"+mark)) return 0;
	this_object()->set_temp("skill_active/"+mark,1);
	call_out("eval_skill", delay, mark, fun);
	return 1;
}

protected void eval_skill(string mark,function fun)
{
	this_object()->delete_temp("skill_active/"+mark);
	evaluate(fun);
}
