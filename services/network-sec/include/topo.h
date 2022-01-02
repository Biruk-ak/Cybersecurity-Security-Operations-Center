#ifndef SOC_NETWORK_SEC_TOPO_H
#define SOC_NETWORK_SEC_TOPO_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_TOPO_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_topo_rec_t;

typedef struct { soc_topo_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_topo_db_t;

soc_topo_db_t *soc_topo_db_create(size_t n);
void soc_topo_db_destroy(soc_topo_db_t *db);
int soc_topo_db_upsert(soc_topo_db_t *db, const soc_topo_rec_t *rec);
int soc_topo_db_remove(soc_topo_db_t *db, uint64_t id);
int soc_topo_db_find(const soc_topo_db_t *db, uint64_t id, soc_topo_rec_t *out);
size_t soc_topo_db_scan(const soc_topo_db_t *db, uint32_t min_sev, soc_topo_rec_t *out, size_t max);
uint64_t soc_topo_hash(const void *p, size_t n);
int soc_topo_validate(const soc_topo_rec_t *rec);
int soc_topo_to_json(const soc_topo_rec_t *rec, char *buf, size_t len);
void soc_topo_metrics(const soc_topo_db_t *db, char *buf, size_t len);
int soc_topo_correlate(soc_topo_db_t *db, const soc_topo_rec_t *seed, soc_topo_rec_t *out, size_t max);
int soc_topo_fn_000(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_001(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_002(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_003(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_004(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_005(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_006(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_007(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_008(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_009(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_010(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_011(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_012(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_013(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_014(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_015(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_016(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_017(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_018(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_019(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_020(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_021(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_022(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_023(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_024(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_025(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_026(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_027(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_028(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_029(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_030(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_031(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_032(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_033(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_034(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_035(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_036(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_037(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_038(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_039(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_040(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_041(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_042(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_043(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_044(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_045(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_046(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_047(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_048(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_049(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_050(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_051(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_052(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_053(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_054(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_055(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_056(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_057(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_058(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_059(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_060(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_061(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_062(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_063(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_064(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_065(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_066(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_067(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_068(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_069(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_070(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_topo_fn_071(soc_topo_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_NETWORK_SEC_TOPO_H */
