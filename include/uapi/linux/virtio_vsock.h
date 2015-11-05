/*
 * This header, excluding the #ifdef __KERNEL__ part, is BSD licensed so
 * anyone can use the definitions to implement compatible drivers/servers:
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of IBM nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL IBM OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Copyright (C) Red Hat, Inc., 2013-2015
 * Copyright (C) Asias He <asias@redhat.com>, 2013
 * Copyright (C) Stefan Hajnoczi <stefanha@redhat.com>, 2015
 */

#ifndef _UAPI_LINUX_VIRTIO_VSOCK_H
#define _UAPI_LINUX_VIRTIO_VOSCK_H

#include <linux/types.h>
#include <linux/virtio_ids.h>
#include <linux/virtio_config.h>

struct virtio_vsock_config {
	__le32 guest_cid;
	__le32 max_virtqueue_pairs;
};

struct virtio_vsock_hdr {
	__le32	src_cid;
	__le32	src_port;
	__le32	dst_cid;
	__le32	dst_port;
	__le32	len;
	/* type can be SOCK_STREAM or SOCK_DGRAM */
	__le16	type;
	/* operations of the pkt */
	__le16	op;
	__le32	flags;
	__le32	buf_alloc;
	__le32	fwd_cnt;
};

enum {
	VIRTIO_VSOCK_OP_INVALID = 0,

	/* Connect operations */
	VIRTIO_VSOCK_OP_REQUEST = 1,
	VIRTIO_VSOCK_OP_RESPONSE = 2,
	VIRTIO_VSOCK_OP_ACK = 3,
	VIRTIO_VSOCK_OP_RST = 4,
	VIRTIO_VSOCK_OP_SHUTDOWN = 5,

	/* To send payload */
	VIRTIO_VSOCK_OP_RW = 6,

	/* Tell the peer our credit info */
	VIRTIO_VSOCK_OP_CREDIT_UPDATE = 7,
	/* Request the peer to send the credit info to us */
	VIRTIO_VSOCK_OP_CREDIT_REQUEST = 8,
};

#endif /* _UAPI_LINUX_VIRTIO_VSOCK_H */
