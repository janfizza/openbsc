#ifndef _MSGB_H
#define _MSGB_H

/* (C) 2008 by Harald Welte <laforge@gnumonks.org>
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

struct bts_link;

struct msgb {
	/* ptr to the incoming (RX) or outgoing (TX) BTS link */
	struct gsm_bts_link *bts_link;

	u_int8_t l2_off;
	u_int8_t l3_off;

	u_int16_t data_len;
	u_int16_t len;

	unsigned char *head;
	unsigned char *tail;
	unsigned char *data;
	unsigned char _data[0];
};

extern struct msgb *msgb_alloc(u_int16_t size);
extern void msgb_free(struct msgb *m);

#define msgb_l2(m)	((void *)(m->data + m->l2_off))
#define msgb_l3(m)	((void *)(m->data + m->l3_off))

static inline unsigned int msgb_headlen(const struct msgb *msgb)
{
	return msgb->len - msgb->data_len;
}
static inline unsigned char *msgb_put(struct msgb *msgb, unsigned int len)
{
	unsigned char *tmp = msgb->tail;
	msgb->tail += len;
	msgb->len += len;
	return tmp;
}
static inline unsigned char *msgb_push(struct msgb *msgb, unsigned int len)
{
	msgb->data -= len;
	msgb->len += len;
	return msgb->data;
}
static inline unsigned char *msgb_pull(struct msgb *msgb, unsigned int len)
{
	msgb->len -= len;
	return msgb->data += len;
}
static inline int msgb_tailroom(const struct msgb *msgb)
{
	return (msgb->data + msgb->data_len) - msgb->tail;
}

#endif /* _MSGB_H */
