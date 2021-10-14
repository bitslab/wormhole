/*
 * Copyright (c) 2016--2021  Wu, Xingbo <wuxb45@gmail.com>
 *
 * All rights reserved. No warranty, explicit or implicit, provided.
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct wormhole;
struct wormref;

// wormhole {{{
// the wh created by wormhole_create() can work with all of safe/unsafe operations.
  extern struct wormhole *
wormhole_create(const struct kvmap_mm * const mm);

  extern struct kv *
wormhole_get(struct wormref * const ref, const struct kref * const key, struct kv * const out);

  extern bool
wormhole_put(struct wormref * const ref, struct kv * const kv);

  extern bool
wormhole_del(struct wormref * const ref, const struct kref * const key);

  extern struct wormhole_iter *
wormhole_iter_create(struct wormref * const ref);

  extern void
wormhole_iter_seek(struct wormhole_iter * const iter, const struct kref * const key);

  extern bool
wormhole_iter_valid(struct wormhole_iter * const iter);

  extern struct kv *
wormhole_iter_peek(struct wormhole_iter * const iter, struct kv * const out);

  extern bool
wormhole_iter_kref(struct wormhole_iter * const iter, struct kref * const kref);

  extern bool
wormhole_iter_kvref(struct wormhole_iter * const iter, struct kvref * const kvref);

  extern void
wormhole_iter_skip1(struct wormhole_iter * const iter);

  extern void
wormhole_iter_skip(struct wormhole_iter * const iter, const u32 nr);

  extern struct kv *
wormhole_iter_next(struct wormhole_iter * const iter, struct kv * const out);

  extern bool
wormhole_iter_inp(struct wormhole_iter * const iter, kv_inp_func uf, void * const priv);

  extern void
wormhole_iter_park(struct wormhole_iter * const iter);

  extern void
wormhole_iter_destroy(struct wormhole_iter * const iter);

  extern struct wormref *
wormhole_ref(struct wormhole * const map);

  extern struct wormhole *
wormhole_unref(struct wormref * const ref);

  extern void
wormhole_park(struct wormref * const ref);

  extern void
wormhole_resume(struct wormref * const ref);

  extern void
wormhole_refresh_qstate(struct wormref * const ref);

// clean with more threads
  extern void
wormhole_clean_th(struct wormhole * const map, const u32 nr_threads);

  extern void
wormhole_clean(struct wormhole * const map);

  extern void
wormhole_destroy(struct wormhole * const map);

// safe API (no need to refresh qstate)

  extern struct kv *
whsafe_get(struct wormref * const ref, const struct kref * const key, struct kv * const out);

  extern bool
whsafe_put(struct wormref * const ref, struct kv * const kv);

  extern bool
whsafe_del(struct wormref * const ref, const struct kref * const key);

// use wormhole_iter_create
  extern void
whsafe_iter_seek(struct wormhole_iter * const iter, const struct kref * const key);

  extern struct kv *
whsafe_iter_peek(struct wormhole_iter * const iter, struct kv * const out);

// use wormhole_iter_valid
// use wormhole_iter_peek
// use wormhole_iter_kref
// use wormhole_iter_kvref
// use wormhole_iter_skip1
// use wormhole_iter_skip
// use wormhole_iter_next
// use wormhole_iter_inp

  extern void
whsafe_iter_park(struct wormhole_iter * const iter);

  extern void
whsafe_iter_destroy(struct wormhole_iter * const iter);

  extern struct wormref *
whsafe_ref(struct wormhole * const map);

// }}} wormhole

#ifdef __cplusplus
}
#endif
// vim:fdm=marker
