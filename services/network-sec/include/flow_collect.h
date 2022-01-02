#ifndef SOC_NETWORK_SEC_FLOW_COLLECT_H
#define SOC_NETWORK_SEC_FLOW_COLLECT_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_FLOW_COLLECT_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_flow_collect_rec_t;

typedef struct { soc_flow_collect_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_flow_collect_db_t;

soc_flow_collect_db_t *soc_flow_collect_db_create(size_t n);
void soc_flow_collect_db_destroy(soc_flow_collect_db_t *db);
int soc_flow_collect_db_upsert(soc_flow_collect_db_t *db, const soc_flow_collect_rec_t *rec);
int soc_flow_collect_db_remove(soc_flow_collect_db_t *db, uint64_t id);
int soc_flow_collect_db_find(const soc_flow_collect_db_t *db, uint64_t id, soc_flow_collect_rec_t *out);
size_t soc_flow_collect_db_scan(const soc_flow_collect_db_t *db, uint32_t min_sev, soc_flow_collect_rec_t *out, size_t max);
uint64_t soc_flow_collect_hash(const void *p, size_t n);
int soc_flow_collect_validate(const soc_flow_collect_rec_t *rec);
int soc_flow_collect_to_json(const soc_flow_collect_rec_t *rec, char *buf, size_t len);
void soc_flow_collect_metrics(const soc_flow_collect_db_t *db, char *buf, size_t len);
int soc_flow_collect_correlate(soc_flow_collect_db_t *db, const soc_flow_collect_rec_t *seed, soc_flow_collect_rec_t *out, size_t max);
int soc_flow_collect_fn_000(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_001(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_002(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_003(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_004(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_005(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_006(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_007(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_008(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_009(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_010(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_011(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_012(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_013(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_014(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_015(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_016(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_017(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_018(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_019(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_020(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_021(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_022(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_023(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_024(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_025(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_026(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_027(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_028(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_029(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_030(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_031(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_032(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_033(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_034(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_035(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_036(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_037(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_038(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_039(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_040(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_041(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_042(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_043(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_044(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_045(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_046(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_047(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_048(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_049(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_050(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_051(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_052(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_053(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_054(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_055(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_056(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_057(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_058(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_059(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_060(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_061(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_062(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_063(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_064(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_065(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_066(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_067(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_068(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_069(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_070(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_flow_collect_fn_071(soc_flow_collect_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_NETWORK_SEC_FLOW_COLLECT_H */
