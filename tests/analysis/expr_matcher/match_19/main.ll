; ModuleID = 'C:\Users\weaut\Documents\GitHub\tsar-test-dev\tests\analysis\expr_matcher\match_19\main.c'
source_filename = "C:\\Users\\weaut\\Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_19\\main.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.28.29334"

; Function Attrs: nounwind uwtable
define dso_local void @far(double* %A, double* %B) #0 !dbg !8 {
entry:
  %B.addr = alloca double*, align 8
  %A.addr = alloca double*, align 8
  %index = alloca i32, align 4
  %i = alloca i32, align 4
  %cleanup.dest.slot = alloca i32, align 4
  %j = alloca i32, align 4
  store double* %B, double** %B.addr, align 8, !tbaa !25
  call void @llvm.dbg.declare(metadata double** %B.addr, metadata !15, metadata !DIExpression()), !dbg !29
  store double* %A, double** %A.addr, align 8, !tbaa !25
  call void @llvm.dbg.declare(metadata double** %A.addr, metadata !16, metadata !DIExpression()), !dbg !30
  %0 = bitcast i32* %index to i8*, !dbg !31
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %0) #4, !dbg !31
  call void @llvm.dbg.declare(metadata i32* %index, metadata !17, metadata !DIExpression()), !dbg !32
  %1 = bitcast i32* %i to i8*, !dbg !33
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %1) #4, !dbg !33
  call void @llvm.dbg.declare(metadata i32* %i, metadata !19, metadata !DIExpression()), !dbg !34
  store i32 0, i32* %i, align 4, !dbg !34, !tbaa !35
  br label %for.cond, !dbg !33

for.cond:                                         ; preds = %for.inc11, %entry
  %2 = load i32, i32* %i, align 4, !dbg !37, !tbaa !35
  %cmp = icmp slt i32 %2, 100, !dbg !38
  br i1 %cmp, label %for.body, label %for.cond.cleanup, !dbg !39

for.cond.cleanup:                                 ; preds = %for.cond
  store i32 2, i32* %cleanup.dest.slot, align 4
  %3 = bitcast i32* %i to i8*, !dbg !40
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %3) #4, !dbg !40
  br label %for.end13

for.body:                                         ; preds = %for.cond
  %4 = bitcast i32* %j to i8*, !dbg !41
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %4) #4, !dbg !41
  call void @llvm.dbg.declare(metadata i32* %j, metadata !21, metadata !DIExpression()), !dbg !42
  store i32 0, i32* %j, align 4, !dbg !42, !tbaa !35
  br label %for.cond1, !dbg !41

for.cond1:                                        ; preds = %for.inc, %for.body
  %5 = load i32, i32* %j, align 4, !dbg !43, !tbaa !35
  %cmp2 = icmp slt i32 %5, 100, !dbg !45
  br i1 %cmp2, label %for.body4, label %for.cond.cleanup3, !dbg !46

for.cond.cleanup3:                                ; preds = %for.cond1
  store i32 5, i32* %cleanup.dest.slot, align 4
  %6 = bitcast i32* %j to i8*, !dbg !47
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %6) #4, !dbg !47
  br label %for.end

for.body4:                                        ; preds = %for.cond1
  %7 = load i32, i32* %i, align 4, !dbg !48, !tbaa !35
  %mul = mul nsw i32 %7, 100, !dbg !50
  %8 = load i32, i32* %j, align 4, !dbg !51, !tbaa !35
  %add = add nsw i32 %mul, %8, !dbg !52
  store i32 %add, i32* %index, align 4, !dbg !53, !tbaa !35
  %9 = load double*, double** %B.addr, align 8, !dbg !54, !tbaa !25
  %10 = load i32, i32* %index, align 4, !dbg !55, !tbaa !35
  %idxprom = sext i32 %10 to i64, !dbg !54
  %arrayidx = getelementptr inbounds double, double* %9, i64 %idxprom, !dbg !54
  %11 = load double, double* %arrayidx, align 8, !dbg !54, !tbaa !56
  %call = call double @boo(double %11), !dbg !58
  %12 = load double*, double** %B.addr, align 8, !dbg !59, !tbaa !25
  %13 = load i32, i32* %index, align 4, !dbg !60, !tbaa !35
  %idxprom5 = sext i32 %13 to i64, !dbg !59
  %arrayidx6 = getelementptr inbounds double, double* %12, i64 %idxprom5, !dbg !59
  store double %call, double* %arrayidx6, align 8, !dbg !61, !tbaa !56
  br label %for.inc, !dbg !62

for.inc:                                          ; preds = %for.body4
  %14 = load i32, i32* %j, align 4, !dbg !63, !tbaa !35
  %inc = add nsw i32 %14, 1, !dbg !63
  store i32 %inc, i32* %j, align 4, !dbg !63, !tbaa !35
  br label %for.cond1, !dbg !47, !llvm.loop !64

for.end:                                          ; preds = %for.cond.cleanup3
  %15 = load double*, double** %B.addr, align 8, !dbg !67, !tbaa !25
  %16 = load i32, i32* %index, align 4, !dbg !68, !tbaa !35
  %idxprom7 = sext i32 %16 to i64, !dbg !67
  %arrayidx8 = getelementptr inbounds double, double* %15, i64 %idxprom7, !dbg !67
  %17 = load double, double* %arrayidx8, align 8, !dbg !67, !tbaa !56
  %18 = load double*, double** %A.addr, align 8, !dbg !69, !tbaa !25
  %19 = load i32, i32* %i, align 4, !dbg !70, !tbaa !35
  %idxprom9 = sext i32 %19 to i64, !dbg !69
  %arrayidx10 = getelementptr inbounds double, double* %18, i64 %idxprom9, !dbg !69
  store double %17, double* %arrayidx10, align 8, !dbg !71, !tbaa !56
  br label %for.inc11, !dbg !72

for.inc11:                                        ; preds = %for.end
  %20 = load i32, i32* %i, align 4, !dbg !73, !tbaa !35
  %inc12 = add nsw i32 %20, 1, !dbg !73
  store i32 %inc12, i32* %i, align 4, !dbg !73, !tbaa !35
  br label %for.cond, !dbg !40, !llvm.loop !74

for.end13:                                        ; preds = %for.cond.cleanup
  %21 = bitcast i32* %index to i8*, !dbg !76
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %21) #4, !dbg !76
  ret void, !dbg !76
}

; Function Attrs: nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #2

declare dso_local double @boo(double) #3

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #2

attributes #0 = { nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable willreturn }
attributes #2 = { argmemonly nounwind willreturn }
attributes #3 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5, !6}
!llvm.ident = !{!7}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 11.0.0 (https://github.com/llvm/llvm-project.git 81eb1c1fa75c6407713b5657156d8d9149572bfe)", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, nameTableKind: None)
!1 = !DIFile(filename: "C:\\Users\\weaut\\Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_19\\main.c", directory: "C:\\Users\\weaut", checksumkind: CSK_MD5, checksum: "be9461a9c0631dcd1c6de2bdb4f0a515")
!2 = !{}
!3 = !{i32 2, !"CodeView", i32 1}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 2}
!6 = !{i32 7, !"PIC Level", i32 2}
!7 = !{!"clang version 11.0.0 (https://github.com/llvm/llvm-project.git 81eb1c1fa75c6407713b5657156d8d9149572bfe)"}
!8 = distinct !DISubprogram(name: "far", scope: !9, file: !9, line: 6, type: !10, scopeLine: 6, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !14)
!9 = !DIFile(filename: "Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_19\\main.c", directory: "C:\\Users\\weaut", checksumkind: CSK_MD5, checksum: "be9461a9c0631dcd1c6de2bdb4f0a515")
!10 = !DISubroutineType(types: !11)
!11 = !{null, !12, !12}
!12 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!13 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!14 = !{!15, !16, !17, !19, !21}
!15 = !DILocalVariable(name: "B", arg: 2, scope: !8, file: !9, line: 6, type: !12)
!16 = !DILocalVariable(name: "A", arg: 1, scope: !8, file: !9, line: 6, type: !12)
!17 = !DILocalVariable(name: "index", scope: !8, file: !9, line: 7, type: !18)
!18 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!19 = !DILocalVariable(name: "i", scope: !20, file: !9, line: 8, type: !18)
!20 = distinct !DILexicalBlock(scope: !8, file: !9, line: 8, column: 3)
!21 = !DILocalVariable(name: "j", scope: !22, file: !9, line: 9, type: !18)
!22 = distinct !DILexicalBlock(scope: !23, file: !9, line: 9, column: 5)
!23 = distinct !DILexicalBlock(scope: !24, file: !9, line: 8, column: 31)
!24 = distinct !DILexicalBlock(scope: !20, file: !9, line: 8, column: 3)
!25 = !{!26, !26, i64 0}
!26 = !{!"any pointer", !27, i64 0}
!27 = !{!"omnipotent char", !28, i64 0}
!28 = !{!"Simple C/C++ TBAA"}
!29 = !DILocation(line: 6, column: 29, scope: !8)
!30 = !DILocation(line: 6, column: 18, scope: !8)
!31 = !DILocation(line: 7, column: 3, scope: !8)
!32 = !DILocation(line: 7, column: 7, scope: !8)
!33 = !DILocation(line: 8, column: 8, scope: !20)
!34 = !DILocation(line: 8, column: 12, scope: !20)
!35 = !{!36, !36, i64 0}
!36 = !{!"int", !27, i64 0}
!37 = !DILocation(line: 8, column: 19, scope: !24)
!38 = !DILocation(line: 8, column: 21, scope: !24)
!39 = !DILocation(line: 8, column: 3, scope: !20)
!40 = !DILocation(line: 8, column: 3, scope: !24)
!41 = !DILocation(line: 9, column: 10, scope: !22)
!42 = !DILocation(line: 9, column: 14, scope: !22)
!43 = !DILocation(line: 9, column: 21, scope: !44)
!44 = distinct !DILexicalBlock(scope: !22, file: !9, line: 9, column: 5)
!45 = !DILocation(line: 9, column: 23, scope: !44)
!46 = !DILocation(line: 9, column: 5, scope: !22)
!47 = !DILocation(line: 9, column: 5, scope: !44)
!48 = !DILocation(line: 10, column: 15, scope: !49)
!49 = distinct !DILexicalBlock(scope: !44, file: !9, line: 9, column: 33)
!50 = !DILocation(line: 10, column: 17, scope: !49)
!51 = !DILocation(line: 10, column: 23, scope: !49)
!52 = !DILocation(line: 10, column: 21, scope: !49)
!53 = !DILocation(line: 10, column: 13, scope: !49)
!54 = !DILocation(line: 11, column: 22, scope: !49)
!55 = !DILocation(line: 11, column: 24, scope: !49)
!56 = !{!57, !57, i64 0}
!57 = !{!"double", !27, i64 0}
!58 = !DILocation(line: 11, column: 18, scope: !49)
!59 = !DILocation(line: 11, column: 7, scope: !49)
!60 = !DILocation(line: 11, column: 9, scope: !49)
!61 = !DILocation(line: 11, column: 16, scope: !49)
!62 = !DILocation(line: 12, column: 5, scope: !49)
!63 = !DILocation(line: 9, column: 28, scope: !44)
!64 = distinct !{!64, !46, !65, !66}
!65 = !DILocation(line: 12, column: 5, scope: !22)
!66 = !{!"llvm.loop.unroll.disable"}
!67 = !DILocation(line: 13, column: 12, scope: !23)
!68 = !DILocation(line: 13, column: 14, scope: !23)
!69 = !DILocation(line: 13, column: 5, scope: !23)
!70 = !DILocation(line: 13, column: 7, scope: !23)
!71 = !DILocation(line: 13, column: 10, scope: !23)
!72 = !DILocation(line: 14, column: 3, scope: !23)
!73 = !DILocation(line: 8, column: 26, scope: !24)
!74 = distinct !{!74, !39, !75, !66}
!75 = !DILocation(line: 14, column: 3, scope: !20)
!76 = !DILocation(line: 15, column: 1, scope: !8)
