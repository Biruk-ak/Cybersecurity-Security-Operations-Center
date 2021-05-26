#ifndef SOC_THREAT_INTEL_FEED_POLLER_H
#define SOC_THREAT_INTEL_FEED_POLLER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_FEED_POLLER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_feed_poller_rec_t;

typedef struct { soc_feed_poller_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_feed_poller_db_t;

soc_feed_poller_db_t *soc_feed_poller_db_create(size_t n);
void soc_feed_poller_db_destroy(soc_feed_poller_db_t *db);
int soc_feed_poller_db_upsert(soc_feed_poller_db_t *db, const soc_feed_poller_rec_t *rec);
int soc_feed_poller_db_remove(soc_feed_poller_db_t *db, uint64_t id);
int soc_feed_poller_db_find(const soc_feed_poller_db_t *db, uint64_t id, soc_feed_poller_rec_t *out);
size_t soc_feed_poller_db_scan(const soc_feed_poller_db_t *db, uint32_t min_sev, soc_feed_poller_rec_t *out, size_t max);
uint64_t soc_feed_poller_hash(const void *p, size_t n);
int soc_feed_poller_validate(const soc_feed_poller_rec_t *rec);
int soc_feed_poller_to_json(const soc_feed_poller_rec_t *rec, char *buf, size_t len);
void soc_feed_poller_metrics(const soc_feed_poller_db_t *db, char *buf, size_t len);
int soc_feed_poller_correlate(soc_feed_poller_db_t *db, const soc_feed_poller_rec_t *seed, soc_feed_poller_rec_t *out, size_t max);
int soc_feed_poller_fn_000(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_001(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_002(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_003(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_004(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_005(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_006(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_007(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_008(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_009(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_010(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_011(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_012(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_013(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_014(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_015(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_016(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_017(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_018(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_019(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_020(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_021(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_022(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_023(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_024(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_025(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_026(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_027(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_028(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_029(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_030(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_031(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_032(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_033(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_034(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_035(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_036(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_037(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_038(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_039(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_040(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_041(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_042(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_043(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_044(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_045(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_046(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_047(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_048(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_049(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_050(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_051(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_052(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_053(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_054(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_055(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_056(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_057(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_058(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_059(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_060(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_061(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_062(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_063(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_064(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_065(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_066(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_067(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_068(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_069(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_070(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_feed_poller_fn_071(soc_feed_poller_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_THREAT_INTEL_FEED_POLLER_H */
