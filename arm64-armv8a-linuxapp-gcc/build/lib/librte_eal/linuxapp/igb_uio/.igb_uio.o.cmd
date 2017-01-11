cmd_/root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/igb_uio.o := gcc -Wp,-MD,/root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/.igb_uio.o.d  -nostdinc -isystem /usr/lib/gcc/aarch64-linux-gnu/4.9/include -I/root/open-estuary/kernel/arch/arm64/include -Iarch/arm64/include/generated/uapi -Iarch/arm64/include/generated  -I/root/open-estuary/kernel/include -Iinclude -I/root/open-estuary/kernel/arch/arm64/include/uapi -Iarch/arm64/include/generated/uapi -I/root/open-estuary/kernel/include/uapi -Iinclude/generated/uapi -include /root/open-estuary/kernel/include/linux/kconfig.h   -I/root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -mgeneral-regs-only -fno-delete-null-pointer-checks -O2 --param=allow-store-data-races=0 -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -g -gdwarf-4 -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -DCC_HAVE_ASM_GOTO   -I/root/lixu/lib/librte_eal/linuxapp/igb_uio --param max-inline-insns-single=100   -I/root/lixu/arm64-armv8a-linuxapp-gcc/include -Winline -Wall -Werror -include /root/lixu/arm64-armv8a-linuxapp-gcc/include/rte_config.h  -DMODULE -mcmodel=large  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(igb_uio)"  -D"KBUILD_MODNAME=KBUILD_STR(igb_uio)" -c -o /root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/.tmp_igb_uio.o /root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/igb_uio.c

source_/root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/igb_uio.o := /root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/igb_uio.c

deps_/root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/igb_uio.o := \
    $(wildcard include/config/xen/dom0.h) \
  /root/lixu/arm64-armv8a-linuxapp-gcc/include/rte_config.h \
    $(wildcard include/config/h.h) \
  /root/open-estuary/kernel/include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/generic/msi/irq/domain.h) \
    $(wildcard include/config/pinctrl.h) \
    $(wildcard include/config/generic/msi/irq.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/dma/cma.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/of.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  /root/open-estuary/kernel/include/linux/ioport.h \
    $(wildcard include/config/memory/hotremove.h) \
  /root/open-estuary/kernel/include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/kasan.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  /root/open-estuary/kernel/include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /root/open-estuary/kernel/include/uapi/linux/types.h \
  arch/arm64/include/generated/asm/types.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/types.h \
  /root/open-estuary/kernel/include/asm-generic/int-ll64.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/int-ll64.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/bitsperlong.h \
  /root/open-estuary/kernel/include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  /root/open-estuary/kernel/include/uapi/asm-generic/bitsperlong.h \
  /root/open-estuary/kernel/include/uapi/linux/posix_types.h \
  /root/open-estuary/kernel/include/linux/stddef.h \
  /root/open-estuary/kernel/include/uapi/linux/stddef.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/posix_types.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/posix_types.h \
  /root/open-estuary/kernel/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
  /root/open-estuary/kernel/include/linux/kobject.h \
    $(wildcard include/config/uevent/helper.h) \
    $(wildcard include/config/debug/kobject/release.h) \
  /root/open-estuary/kernel/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  /root/open-estuary/kernel/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  /root/open-estuary/kernel/include/uapi/linux/const.h \
  /root/open-estuary/kernel/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/panic/timeout.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/lib/gcc/aarch64-linux-gnu/4.9/include/stdarg.h \
  /root/open-estuary/kernel/include/linux/linkage.h \
  /root/open-estuary/kernel/include/linux/stringify.h \
  /root/open-estuary/kernel/include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/linkage.h \
  /root/open-estuary/kernel/include/linux/bitops.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/bitops.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/barrier.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/builtin-__ffs.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/builtin-ffs.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/builtin-__fls.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/builtin-fls.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/ffz.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/fls64.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  /root/open-estuary/kernel/include/asm-generic/bitops/sched.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/hweight.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/arch_hweight.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/const_hweight.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/lock.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/non-atomic.h \
  /root/open-estuary/kernel/include/asm-generic/bitops/le.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/byteorder.h \
  /root/open-estuary/kernel/include/linux/byteorder/little_endian.h \
  /root/open-estuary/kernel/include/uapi/linux/byteorder/little_endian.h \
  /root/open-estuary/kernel/include/linux/swab.h \
  /root/open-estuary/kernel/include/uapi/linux/swab.h \
  arch/arm64/include/generated/asm/swab.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/swab.h \
  /root/open-estuary/kernel/include/linux/byteorder/generic.h \
  /root/open-estuary/kernel/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  /root/open-estuary/kernel/include/linux/typecheck.h \
  /root/open-estuary/kernel/include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/early/printk.h) \
  /root/open-estuary/kernel/include/linux/init.h \
    $(wildcard include/config/broken/rodata.h) \
    $(wildcard include/config/lto.h) \
  /root/open-estuary/kernel/include/linux/kern_levels.h \
  /root/open-estuary/kernel/include/linux/cache.h \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  /root/open-estuary/kernel/include/uapi/linux/kernel.h \
  /root/open-estuary/kernel/include/uapi/linux/sysinfo.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/cache.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/cachetype.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/cputype.h \
  /root/open-estuary/kernel/include/linux/dynamic_debug.h \
  /root/open-estuary/kernel/include/linux/sysfs.h \
    $(wildcard include/config/debug/lock/alloc.h) \
    $(wildcard include/config/sysfs.h) \
  /root/open-estuary/kernel/include/linux/kernfs.h \
    $(wildcard include/config/kernfs.h) \
  /root/open-estuary/kernel/include/linux/err.h \
  arch/arm64/include/generated/asm/errno.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/errno.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/errno-base.h \
  /root/open-estuary/kernel/include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/mutex/spin/on/owner.h) \
  arch/arm64/include/generated/asm/current.h \
  /root/open-estuary/kernel/include/asm-generic/current.h \
  /root/open-estuary/kernel/include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/debug/stack/usage.h) \
  /root/open-estuary/kernel/include/linux/bug.h \
    $(wildcard include/config/generic/bug.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/bug.h \
    $(wildcard include/config/debug/bugverbose.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/debug-monitors.h \
    $(wildcard include/config/have/hw/breakpoint.h) \
  /root/open-estuary/kernel/include/linux/errno.h \
  /root/open-estuary/kernel/include/uapi/linux/errno.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/esr.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/memory.h \
    $(wildcard include/config/arm64/va/bits.h) \
  arch/arm64/include/generated/asm/sizes.h \
  /root/open-estuary/kernel/include/asm-generic/sizes.h \
  /root/open-estuary/kernel/include/linux/sizes.h \
  /root/open-estuary/kernel/include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/insn.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/ptrace.h \
    $(wildcard include/config/cpu/big/endian.h) \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/ptrace.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/hwcap.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/hwcap.h \
  /root/open-estuary/kernel/include/asm-generic/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/thread_info.h \
    $(wildcard include/config/arm64/4k/pages.h) \
    $(wildcard include/config/arm64/16k/pages.h) \
  /root/open-estuary/kernel/include/linux/spinlock_types.h \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/debug/spinlock.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/spinlock_types.h \
  /root/open-estuary/kernel/include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/trace/irqflags.h) \
  /root/open-estuary/kernel/include/linux/rwlock_types.h \
  /root/open-estuary/kernel/include/linux/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/atomic.h \
    $(wildcard include/config/arm64/lse/atomics.h) \
    $(wildcard include/config/as/lse.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/lse.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/atomic_ll_sc.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/cmpxchg.h \
  /root/open-estuary/kernel/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
  /root/open-estuary/kernel/include/asm-generic/atomic-long.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/processor.h \
  /root/open-estuary/kernel/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /root/open-estuary/kernel/include/uapi/linux/string.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/string.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/fpsimd.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/hw_breakpoint.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/cpufeature.h \
    $(wildcard include/config/hotplug/cpu.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/sysreg.h \
    $(wildcard include/config/arm64/64k/pages.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/opcodes.h \
    $(wildcard include/config/cpu/endian/be8.h) \
  /root/open-estuary/kernel/arch/arm64/include/../../arm/include/asm/opcodes.h \
    $(wildcard include/config/cpu/endian/be32.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/pgtable-hwdef.h \
    $(wildcard include/config/pgtable/levels.h) \
  /root/open-estuary/kernel/include/linux/osq_lock.h \
  /root/open-estuary/kernel/include/linux/idr.h \
  /root/open-estuary/kernel/include/linux/rcupdate.h \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/trace.h) \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/rcu/stall/common.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/tasks/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/rcu/nocb/cpu/all.h) \
    $(wildcard include/config/no/hz/full/sysidle.h) \
  /root/open-estuary/kernel/include/linux/spinlock.h \
  /root/open-estuary/kernel/include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  arch/arm64/include/generated/asm/preempt.h \
  /root/open-estuary/kernel/include/asm-generic/preempt.h \
  /root/open-estuary/kernel/include/linux/irqflags.h \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/irqflags.h \
  /root/open-estuary/kernel/include/linux/bottom_half.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/spinlock.h \
  /root/open-estuary/kernel/include/linux/rwlock.h \
  /root/open-estuary/kernel/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  /root/open-estuary/kernel/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  /root/open-estuary/kernel/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  /root/open-estuary/kernel/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  /root/open-estuary/kernel/include/linux/bitmap.h \
  /root/open-estuary/kernel/include/linux/seqlock.h \
  /root/open-estuary/kernel/include/linux/completion.h \
  /root/open-estuary/kernel/include/linux/wait.h \
  /root/open-estuary/kernel/include/uapi/linux/wait.h \
  /root/open-estuary/kernel/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  /root/open-estuary/kernel/include/linux/ktime.h \
  /root/open-estuary/kernel/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  /root/open-estuary/kernel/include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  arch/arm64/include/generated/asm/div64.h \
  /root/open-estuary/kernel/include/asm-generic/div64.h \
  /root/open-estuary/kernel/include/linux/time64.h \
  /root/open-estuary/kernel/include/uapi/linux/time.h \
  /root/open-estuary/kernel/include/linux/jiffies.h \
  /root/open-estuary/kernel/include/linux/timex.h \
  /root/open-estuary/kernel/include/uapi/linux/timex.h \
  /root/open-estuary/kernel/include/uapi/linux/param.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/param.h \
  /root/open-estuary/kernel/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  /root/open-estuary/kernel/include/uapi/asm-generic/param.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/timex.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/arch_timer.h \
  /root/open-estuary/kernel/include/clocksource/arm_arch_timer.h \
    $(wildcard include/config/arm/arch/timer.h) \
  /root/open-estuary/kernel/include/linux/timecounter.h \
  /root/open-estuary/kernel/include/asm-generic/timex.h \
  include/generated/timeconst.h \
  /root/open-estuary/kernel/include/linux/timekeeping.h \
  /root/open-estuary/kernel/include/linux/rcutree.h \
  /root/open-estuary/kernel/include/linux/rbtree.h \
  /root/open-estuary/kernel/include/linux/kobject_ns.h \
  /root/open-estuary/kernel/include/linux/stat.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/stat.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/stat.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/stat.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/compat.h \
  /root/open-estuary/kernel/include/linux/sched.h \
    $(wildcard include/config/no/hz/common.h) \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/lockup/detector.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
    $(wildcard include/config/virt/cpu/accounting/native.h) \
    $(wildcard include/config/sched/autogroup.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/bpf/syscall.h) \
    $(wildcard include/config/sched/info.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/memcg/kmem.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cc/stackprotector.h) \
    $(wildcard include/config/virt/cpu/accounting/gen.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/arch/want/batched/unmap/tlb/flush.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/uprobes.h) \
    $(wildcard include/config/bcache.h) \
    $(wildcard include/config/arch/wants/dynamic/task/struct.h) \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/have/copy/thread/tls.h) \
  /root/open-estuary/kernel/include/uapi/linux/sched.h \
  /root/open-estuary/kernel/include/linux/sched/prio.h \
  /root/open-estuary/kernel/include/linux/capability.h \
    $(wildcard include/config/multiuser.h) \
  /root/open-estuary/kernel/include/uapi/linux/capability.h \
  /root/open-estuary/kernel/include/linux/plist.h \
    $(wildcard include/config/debug/pi/list.h) \
  /root/open-estuary/kernel/include/linux/nodemask.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/movable/node.h) \
  /root/open-estuary/kernel/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  /root/open-estuary/kernel/include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/arch/enable/split/pmd/ptlock.h) \
    $(wildcard include/config/have/cmpxchg/double.h) \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/userfaultfd.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/x86/intel/mpx.h) \
    $(wildcard include/config/hugetlb/page.h) \
  /root/open-estuary/kernel/include/linux/auxvec.h \
  /root/open-estuary/kernel/include/uapi/linux/auxvec.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/auxvec.h \
  /root/open-estuary/kernel/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/spin/on/owner.h) \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  arch/arm64/include/generated/asm/rwsem.h \
  /root/open-estuary/kernel/include/asm-generic/rwsem.h \
  /root/open-estuary/kernel/include/linux/uprobes.h \
  /root/open-estuary/kernel/include/linux/page-flags-layout.h \
  include/generated/bounds.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/sparsemem.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/page.h \
    $(wildcard include/config/have/arch/pfn/valid.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/pgtable-types.h \
  /root/open-estuary/kernel/include/asm-generic/pgtable-nopud.h \
  /root/open-estuary/kernel/include/asm-generic/getorder.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/mmu.h \
  /root/open-estuary/kernel/include/linux/cputime.h \
  arch/arm64/include/generated/asm/cputime.h \
  /root/open-estuary/kernel/include/asm-generic/cputime.h \
    $(wildcard include/config/virt/cpu/accounting.h) \
  /root/open-estuary/kernel/include/asm-generic/cputime_jiffies.h \
  /root/open-estuary/kernel/include/linux/smp.h \
    $(wildcard include/config/up/late/init.h) \
  /root/open-estuary/kernel/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/smp.h \
    $(wildcard include/config/arm64/acpi/parking/protocol.h) \
  /root/open-estuary/kernel/include/linux/sem.h \
  /root/open-estuary/kernel/include/uapi/linux/sem.h \
  /root/open-estuary/kernel/include/linux/ipc.h \
  /root/open-estuary/kernel/include/linux/uidgid.h \
    $(wildcard include/config/user/ns.h) \
  /root/open-estuary/kernel/include/linux/highuid.h \
  /root/open-estuary/kernel/include/uapi/linux/ipc.h \
  arch/arm64/include/generated/asm/ipcbuf.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/ipcbuf.h \
  arch/arm64/include/generated/asm/sembuf.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/sembuf.h \
  /root/open-estuary/kernel/include/linux/shm.h \
  /root/open-estuary/kernel/include/uapi/linux/shm.h \
  arch/arm64/include/generated/asm/shmbuf.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/shmbuf.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/shmparam.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/shmparam.h \
  /root/open-estuary/kernel/include/linux/signal.h \
    $(wildcard include/config/old/sigaction.h) \
  /root/open-estuary/kernel/include/uapi/linux/signal.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/signal.h \
  /root/open-estuary/kernel/include/asm-generic/signal.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/signal.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/signal-defs.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/sigcontext.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/siginfo.h \
  /root/open-estuary/kernel/include/asm-generic/siginfo.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/siginfo.h \
  /root/open-estuary/kernel/include/linux/pid.h \
  /root/open-estuary/kernel/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  /root/open-estuary/kernel/include/linux/pfn.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/percpu.h \
  /root/open-estuary/kernel/include/asm-generic/percpu.h \
  /root/open-estuary/kernel/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  /root/open-estuary/kernel/include/linux/topology.h \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
  /root/open-estuary/kernel/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/cma.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/zone/device.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/page/extension.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/deferred/struct/page/init.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  /root/open-estuary/kernel/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  /root/open-estuary/kernel/include/linux/memory_hotplug.h \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  /root/open-estuary/kernel/include/linux/notifier.h \
  /root/open-estuary/kernel/include/linux/srcu.h \
  /root/open-estuary/kernel/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
  /root/open-estuary/kernel/include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  /root/open-estuary/kernel/include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  /root/open-estuary/kernel/include/uapi/linux/sysctl.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/mmzone.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/numa.h \
    $(wildcard include/config/of/numa.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/topology.h \
  /root/open-estuary/kernel/include/asm-generic/topology.h \
  /root/open-estuary/kernel/include/linux/proportions.h \
  /root/open-estuary/kernel/include/linux/percpu_counter.h \
  /root/open-estuary/kernel/include/linux/gfp.h \
  /root/open-estuary/kernel/include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/have/arch/seccomp/filter.h) \
    $(wildcard include/config/seccomp/filter.h) \
    $(wildcard include/config/checkpoint/restore.h) \
  /root/open-estuary/kernel/include/uapi/linux/seccomp.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/seccomp.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/unistd.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/unistd.h \
  /root/open-estuary/kernel/include/asm-generic/unistd.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/unistd.h \
  /root/open-estuary/kernel/include/asm-generic/seccomp.h \
  /root/open-estuary/kernel/include/uapi/linux/unistd.h \
  /root/open-estuary/kernel/include/linux/rculist.h \
  /root/open-estuary/kernel/include/linux/rtmutex.h \
    $(wildcard include/config/debug/rt/mutexes.h) \
  /root/open-estuary/kernel/include/linux/resource.h \
  /root/open-estuary/kernel/include/uapi/linux/resource.h \
  arch/arm64/include/generated/asm/resource.h \
  /root/open-estuary/kernel/include/asm-generic/resource.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/resource.h \
  /root/open-estuary/kernel/include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/time/low/res.h) \
    $(wildcard include/config/timerfd.h) \
  /root/open-estuary/kernel/include/linux/timerqueue.h \
  /root/open-estuary/kernel/include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  /root/open-estuary/kernel/include/linux/latencytop.h \
  /root/open-estuary/kernel/include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
    $(wildcard include/config/security.h) \
  /root/open-estuary/kernel/include/linux/key.h \
  /root/open-estuary/kernel/include/linux/assoc_array.h \
    $(wildcard include/config/associative/array.h) \
  /root/open-estuary/kernel/include/linux/selinux.h \
    $(wildcard include/config/security/selinux.h) \
  /root/open-estuary/kernel/include/uapi/linux/magic.h \
  /root/open-estuary/kernel/include/linux/cgroup-defs.h \
  /root/open-estuary/kernel/include/uapi/linux/limits.h \
  /root/open-estuary/kernel/include/linux/percpu-refcount.h \
  /root/open-estuary/kernel/include/linux/percpu-rwsem.h \
  /root/open-estuary/kernel/include/linux/rcu_sync.h \
  /root/open-estuary/kernel/include/linux/cgroup_subsys.h \
    $(wildcard include/config/cgroup/cpuacct.h) \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/cgroup/device.h) \
    $(wildcard include/config/cgroup/freezer.h) \
    $(wildcard include/config/cgroup/net/classid.h) \
    $(wildcard include/config/cgroup/perf.h) \
    $(wildcard include/config/cgroup/net/prio.h) \
    $(wildcard include/config/cgroup/hugetlb.h) \
    $(wildcard include/config/cgroup/pids.h) \
    $(wildcard include/config/cgroup/debug.h) \
  /root/open-estuary/kernel/include/uapi/linux/stat.h \
  /root/open-estuary/kernel/include/linux/kref.h \
  /root/open-estuary/kernel/include/linux/klist.h \
  /root/open-estuary/kernel/include/linux/pinctrl/devinfo.h \
    $(wildcard include/config/pm.h) \
  /root/open-estuary/kernel/include/linux/pinctrl/consumer.h \
  /root/open-estuary/kernel/include/linux/seq_file.h \
  /root/open-estuary/kernel/include/linux/pinctrl/pinctrl-state.h \
  /root/open-estuary/kernel/include/linux/pm.h \
    $(wildcard include/config/vt/console/sleep.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  /root/open-estuary/kernel/include/linux/ratelimit.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/device.h \
    $(wildcard include/config/iommu/api.h) \
    $(wildcard include/config/arm64/dma/use/iommu.h) \
  /root/open-estuary/kernel/include/linux/pm_wakeup.h \
  /root/open-estuary/kernel/include/linux/module.h \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/modules/tree/lookup.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/livepatch.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/debug/set/module/ronx.h) \
  /root/open-estuary/kernel/include/linux/kmod.h \
  /root/open-estuary/kernel/include/linux/elf.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/elf.h \
  arch/arm64/include/generated/asm/user.h \
  /root/open-estuary/kernel/include/asm-generic/user.h \
  /root/open-estuary/kernel/include/uapi/linux/elf.h \
  /root/open-estuary/kernel/include/uapi/linux/elf-em.h \
  /root/open-estuary/kernel/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  /root/open-estuary/kernel/include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/jump_label.h \
  /root/open-estuary/kernel/include/linux/rbtree_latch.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/module.h \
  /root/open-estuary/kernel/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  /root/open-estuary/kernel/include/linux/pci.h \
    $(wildcard include/config/pci/iov.h) \
    $(wildcard include/config/pcieaspm.h) \
    $(wildcard include/config/pci/msi.h) \
    $(wildcard include/config/pci/ats.h) \
    $(wildcard include/config/pci/domains/generic.h) \
    $(wildcard include/config/pci/bus/addr/t/64bit.h) \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/pcieportbus.h) \
    $(wildcard include/config/pcieaer.h) \
    $(wildcard include/config/pcie/ecrc.h) \
    $(wildcard include/config/ht/irq.h) \
    $(wildcard include/config/pci/domains.h) \
    $(wildcard include/config/pci/quirks.h) \
    $(wildcard include/config/hibernate/callbacks.h) \
    $(wildcard include/config/pci/mmconfig.h) \
    $(wildcard include/config/hotplug/pci.h) \
    $(wildcard include/config/acpi.h) \
    $(wildcard include/config/eeh.h) \
  /root/open-estuary/kernel/include/linux/mod_devicetable.h \
  /root/open-estuary/kernel/include/linux/uuid.h \
  /root/open-estuary/kernel/include/uapi/linux/uuid.h \
  /root/open-estuary/kernel/include/linux/io.h \
    $(wildcard include/config/have/arch/huge/vmap.h) \
    $(wildcard include/config/has/ioport/map.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/io.h \
    $(wildcard include/config/arm64/indirect/pio.h) \
  /root/open-estuary/kernel/include/linux/blk_types.h \
    $(wildcard include/config/blk/dev/integrity.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/pgtable.h \
    $(wildcard include/config/arm64/hw/afdbm.h) \
    $(wildcard include/config/have/rcu/table/free.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/proc-fns.h \
  /root/open-estuary/kernel/include/asm-generic/pgtable.h \
    $(wildcard include/config/have/arch/soft/dirty.h) \
  arch/arm64/include/generated/asm/early_ioremap.h \
  /root/open-estuary/kernel/include/asm-generic/early_ioremap.h \
    $(wildcard include/config/generic/early/ioremap.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/alternative.h \
    $(wildcard include/config/foo.h) \
  /root/open-estuary/kernel/include/xen/xen.h \
    $(wildcard include/config/xen.h) \
    $(wildcard include/config/xen/pvh.h) \
  /root/open-estuary/kernel/include/xen/interface/xen.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/xen/interface.h \
  /root/open-estuary/kernel/arch/arm64/include/../../arm/include/asm/xen/interface.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/xen/hypervisor.h \
  /root/open-estuary/kernel/arch/arm64/include/../../arm/include/asm/xen/hypervisor.h \
  /root/open-estuary/kernel/include/asm-generic/io.h \
    $(wildcard include/config/generic/iomap.h) \
    $(wildcard include/config/virt/to/bus.h) \
  /root/open-estuary/kernel/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /root/open-estuary/kernel/include/linux/vmalloc.h \
  /root/open-estuary/kernel/include/linux/resource_ext.h \
  /root/open-estuary/kernel/include/linux/slab.h \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/slab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
  /root/open-estuary/kernel/include/linux/kmemleak.h \
    $(wildcard include/config/debug/kmemleak.h) \
  /root/open-estuary/kernel/include/linux/kasan.h \
  /root/open-estuary/kernel/include/uapi/linux/pci.h \
  /root/open-estuary/kernel/include/uapi/linux/pci_regs.h \
  /root/open-estuary/kernel/include/linux/pci_ids.h \
  /root/open-estuary/kernel/include/linux/pci-dma.h \
  /root/open-estuary/kernel/include/linux/dmapool.h \
  /root/open-estuary/kernel/include/linux/scatterlist.h \
    $(wildcard include/config/debug/sg.h) \
    $(wildcard include/config/need/sg/dma/length.h) \
  /root/open-estuary/kernel/include/linux/mm.h \
    $(wildcard include/config/mem/soft/dirty.h) \
    $(wildcard include/config/x86.h) \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/parisc.h) \
    $(wildcard include/config/metag.h) \
    $(wildcard include/config/shmem.h) \
    $(wildcard include/config/debug/vm/rb.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/hugetlbfs.h) \
  /root/open-estuary/kernel/include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  /root/open-estuary/kernel/include/linux/range.h \
  /root/open-estuary/kernel/include/linux/bit_spinlock.h \
  /root/open-estuary/kernel/include/linux/shrinker.h \
  /root/open-estuary/kernel/include/linux/page_ext.h \
    $(wildcard include/config/idle/page/tracking.h) \
    $(wildcard include/config/page/owner.h) \
  /root/open-estuary/kernel/include/linux/stacktrace.h \
    $(wildcard include/config/stacktrace.h) \
    $(wildcard include/config/user/stacktrace/support.h) \
  /root/open-estuary/kernel/include/linux/page-flags.h \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/ksm.h) \
  /root/open-estuary/kernel/include/linux/huge_mm.h \
  /root/open-estuary/kernel/include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
    $(wildcard include/config/debug/tlbflush.h) \
    $(wildcard include/config/debug/vm/vmacache.h) \
  /root/open-estuary/kernel/include/linux/vm_event_item.h \
    $(wildcard include/config/migration.h) \
    $(wildcard include/config/memory/balloon.h) \
    $(wildcard include/config/balloon/compaction.h) \
  /root/open-estuary/kernel/arch/arm64/include/asm/pci.h \
  /root/open-estuary/kernel/include/linux/dma-mapping.h \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/arch/has/dma/set/coherent/mask.h) \
    $(wildcard include/config/have/dma/attrs.h) \
    $(wildcard include/config/need/dma/map/state.h) \
  /root/open-estuary/kernel/include/linux/dma-attrs.h \
  /root/open-estuary/kernel/include/linux/dma-direction.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/dma-mapping.h \
    $(wildcard include/config/iommu/dma.h) \
  /root/open-estuary/kernel/include/asm-generic/dma-mapping-common.h \
  /root/open-estuary/kernel/include/linux/kmemcheck.h \
  /root/open-estuary/kernel/include/linux/dma-debug.h \
    $(wildcard include/config/dma/api/debug.h) \
  /root/open-estuary/kernel/include/asm-generic/dma-coherent.h \
    $(wildcard include/config/have/generic/dma/coherent.h) \
  /root/open-estuary/kernel/include/asm-generic/pci-bridge.h \
  /root/open-estuary/kernel/include/asm-generic/pci-dma-compat.h \
  /root/open-estuary/kernel/include/linux/uio_driver.h \
  /root/open-estuary/kernel/include/linux/fs.h \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/cgroup/writeback.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fs/dax.h) \
  /root/open-estuary/kernel/include/linux/kdev_t.h \
  /root/open-estuary/kernel/include/uapi/linux/kdev_t.h \
  /root/open-estuary/kernel/include/linux/dcache.h \
  /root/open-estuary/kernel/include/linux/rculist_bl.h \
  /root/open-estuary/kernel/include/linux/list_bl.h \
  /root/open-estuary/kernel/include/linux/lockref.h \
    $(wildcard include/config/arch/use/cmpxchg/lockref.h) \
  /root/open-estuary/kernel/include/linux/path.h \
  /root/open-estuary/kernel/include/linux/list_lru.h \
  /root/open-estuary/kernel/include/linux/radix-tree.h \
  /root/open-estuary/kernel/include/linux/semaphore.h \
  /root/open-estuary/kernel/include/uapi/linux/fiemap.h \
  /root/open-estuary/kernel/include/linux/migrate_mode.h \
  /root/open-estuary/kernel/include/uapi/linux/fs.h \
  /root/open-estuary/kernel/include/uapi/linux/ioctl.h \
  arch/arm64/include/generated/asm/ioctl.h \
  /root/open-estuary/kernel/include/asm-generic/ioctl.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/ioctl.h \
  /root/open-estuary/kernel/include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  /root/open-estuary/kernel/include/uapi/linux/dqblk_xfs.h \
  /root/open-estuary/kernel/include/linux/dqblk_v1.h \
  /root/open-estuary/kernel/include/linux/dqblk_v2.h \
  /root/open-estuary/kernel/include/linux/dqblk_qtree.h \
  /root/open-estuary/kernel/include/linux/projid.h \
  /root/open-estuary/kernel/include/uapi/linux/quota.h \
  /root/open-estuary/kernel/include/linux/nfs_fs_i.h \
  /root/open-estuary/kernel/include/linux/fcntl.h \
  /root/open-estuary/kernel/include/uapi/linux/fcntl.h \
  /root/open-estuary/kernel/arch/arm64/include/uapi/asm/fcntl.h \
  /root/open-estuary/kernel/include/uapi/asm-generic/fcntl.h \
  /root/open-estuary/kernel/include/linux/interrupt.h \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
  /root/open-estuary/kernel/include/linux/irqreturn.h \
  /root/open-estuary/kernel/include/linux/irqnr.h \
  /root/open-estuary/kernel/include/uapi/linux/irqnr.h \
  /root/open-estuary/kernel/include/linux/hardirq.h \
  /root/open-estuary/kernel/include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  /root/open-estuary/kernel/include/linux/vtime.h \
  /root/open-estuary/kernel/include/linux/context_tracking_state.h \
    $(wildcard include/config/context/tracking.h) \
  /root/open-estuary/kernel/include/linux/static_key.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/hardirq.h \
  /root/open-estuary/kernel/arch/arm64/include/asm/irq.h \
  /root/open-estuary/kernel/include/asm-generic/irq.h \
  /root/open-estuary/kernel/include/linux/irq_cpustat.h \
  /root/open-estuary/kernel/include/linux/msi.h \
    $(wildcard include/config/pci/msi/irq/domain.h) \
  /root/open-estuary/kernel/include/linux/irqhandler.h \
  arch/arm64/include/generated/asm/msi.h \
  /root/open-estuary/kernel/include/asm-generic/msi.h \
  include/generated/uapi/linux/version.h \
  /root/lixu/arm64-armv8a-linuxapp-gcc/include/rte_pci_dev_features.h \
  /root/lixu/arm64-armv8a-linuxapp-gcc/include/rte_pci_dev_feature_defs.h \
  /root/lixu/lib/librte_eal/linuxapp/igb_uio/compat.h \

/root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/igb_uio.o: $(deps_/root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/igb_uio.o)

$(deps_/root/lixu/arm64-armv8a-linuxapp-gcc/build/lib/librte_eal/linuxapp/igb_uio/igb_uio.o):
