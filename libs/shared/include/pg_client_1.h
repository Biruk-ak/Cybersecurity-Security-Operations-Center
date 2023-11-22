#ifndef SOC_SHARED_PG_CLIENT_1_H
#define SOC_SHARED_PG_CLIENT_1_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PG_CLIENT_1_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_pg_client_1_rec_t;

typedef struct { soc_pg_client_1_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_pg_client_1_db_t;

soc_pg_client_1_db_t *soc_pg_client_1_db_create(size_t n);
void soc_pg_client_1_db_destroy(soc_pg_client_1_db_t *db);
int soc_pg_client_1_db_upsert(soc_pg_client_1_db_t *db, const soc_pg_client_1_rec_t *rec);
int soc_pg_client_1_db_remove(soc_pg_client_1_db_t *db, uint64_t id);
int soc_pg_client_1_db_find(const soc_pg_client_1_db_t *db, uint64_t id, soc_pg_client_1_rec_t *out);
size_t soc_pg_client_1_db_scan(const soc_pg_client_1_db_t *db, uint32_t min_sev, soc_pg_client_1_rec_t *out, size_t max);
uint64_t soc_pg_client_1_hash(const void *p, size_t n);
int soc_pg_client_1_validate(const soc_pg_client_1_rec_t *rec);
int soc_pg_client_1_to_json(const soc_pg_client_1_rec_t *rec, char *buf, size_t len);
void soc_pg_client_1_metrics(const soc_pg_client_1_db_t *db, char *buf, size_t len);
int soc_pg_client_1_correlate(soc_pg_client_1_db_t *db, const soc_pg_client_1_rec_t *seed, soc_pg_client_1_rec_t *out, size_t max);
int soc_pg_client_1_fn_000(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_001(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_002(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_003(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_004(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_005(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_006(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_007(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_008(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_009(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_010(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_011(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_012(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_013(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_014(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_015(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_016(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_017(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_018(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_019(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_020(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_021(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_022(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_023(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_024(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_025(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_026(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_027(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_028(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_029(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_030(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_031(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_032(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_033(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_034(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_035(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_036(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_037(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_038(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_039(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_040(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_041(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_042(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_043(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_044(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_045(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_046(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_047(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_048(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_049(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_050(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_051(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_052(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_053(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_054(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_055(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_056(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_057(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_058(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_059(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_060(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_061(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_062(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_063(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_064(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_065(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_066(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_067(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_068(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_069(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_070(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_071(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_072(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_073(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pg_client_1_fn_074(soc_pg_client_1_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SHARED_PG_CLIENT_1_H */
