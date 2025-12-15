#ifndef SOC_XDR_EXT_KILL_CHAIN_H
#define SOC_XDR_EXT_KILL_CHAIN_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_KILL_CHAIN_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_kill_chain_rec_t;

typedef struct { soc_kill_chain_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_kill_chain_db_t;

soc_kill_chain_db_t *soc_kill_chain_db_create(size_t n);
void soc_kill_chain_db_destroy(soc_kill_chain_db_t *db);
int soc_kill_chain_db_upsert(soc_kill_chain_db_t *db, const soc_kill_chain_rec_t *rec);
int soc_kill_chain_db_remove(soc_kill_chain_db_t *db, uint64_t id);
int soc_kill_chain_db_find(const soc_kill_chain_db_t *db, uint64_t id, soc_kill_chain_rec_t *out);
size_t soc_kill_chain_db_scan(const soc_kill_chain_db_t *db, uint32_t min_sev, soc_kill_chain_rec_t *out, size_t max);
uint64_t soc_kill_chain_hash(const void *p, size_t n);
int soc_kill_chain_validate(const soc_kill_chain_rec_t *rec);
int soc_kill_chain_to_json(const soc_kill_chain_rec_t *rec, char *buf, size_t len);
void soc_kill_chain_metrics(const soc_kill_chain_db_t *db, char *buf, size_t len);
int soc_kill_chain_correlate(soc_kill_chain_db_t *db, const soc_kill_chain_rec_t *seed, soc_kill_chain_rec_t *out, size_t max);
int soc_kill_chain_fn_000(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_001(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_002(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_003(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_004(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_005(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_006(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_007(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_008(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_009(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_010(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_011(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_012(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_013(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_014(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_015(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_016(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_017(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_018(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_019(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_020(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_021(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_022(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_023(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_024(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_025(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_026(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_027(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_028(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_029(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_030(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_031(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_032(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_033(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_034(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_035(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_036(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_037(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_038(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_039(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_040(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_041(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_042(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_043(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_044(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_045(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_046(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_047(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_048(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_049(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_050(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_051(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_052(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_053(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_054(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_055(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_056(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_057(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_058(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_059(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_060(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_061(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_062(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_063(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_064(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_065(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_066(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_067(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_068(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_069(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_070(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_071(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_072(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_073(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_074(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_075(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_076(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_077(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_078(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_kill_chain_fn_079(soc_kill_chain_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_XDR_EXT_KILL_CHAIN_H */
