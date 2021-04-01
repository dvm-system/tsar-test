; ModuleID = 'C:\Users\weaut\Documents\GitHub\tsar-test-dev\tests\analysis\expr_matcher\match_20\main.c'
source_filename = "C:\\Users\\weaut\\Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_20\\main.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.28.29334"

; Function Attrs: nounwind uwtable
define dso_local void @far(double* %A) #0 !dbg !8 {
entry:
  %A.addr = alloca double*, align 8
  %i = alloca i32, align 4
  store double* %A, double** %A.addr, align 8, !tbaa !19
  call void @llvm.dbg.declare(metadata double** %A.addr, metadata !15, metadata !DIExpression()), !dbg !23
  %0 = bitcast i32* %i to i8*, !dbg !24
  call void @llvm.lifetime.start.p0i8(i64 4, i8* %0) #4, !dbg !24
  call void @llvm.dbg.declare(metadata i32* %i, metadata !16, metadata !DIExpression()), !dbg !25
  store i32 1, i32* %i, align 4, !dbg !25, !tbaa !26
  br label %for.cond, !dbg !24

for.cond:                                         ; preds = %for.inc, %entry
  %1 = load i32, i32* %i, align 4, !dbg !28, !tbaa !26
  %cmp = icmp slt i32 %1, 99, !dbg !30
  br i1 %cmp, label %for.body, label %for.cond.cleanup, !dbg !31

for.cond.cleanup:                                 ; preds = %for.cond
  %2 = bitcast i32* %i to i8*, !dbg !32
  call void @llvm.lifetime.end.p0i8(i64 4, i8* %2) #4, !dbg !32
  br label %for.end

for.body:                                         ; preds = %for.cond
  %3 = load i32, i32* %i, align 4, !dbg !33, !tbaa !26
  %call = call i32 @is_prime(i32 %3), !dbg !36
  %tobool = icmp ne i32 %call, 0, !dbg !36
  br i1 %tobool, label %if.then, label %if.end, !dbg !37

if.then:                                          ; preds = %for.body
  %4 = load double*, double** %A.addr, align 8, !dbg !38, !tbaa !19
  %5 = load i32, i32* %i, align 4, !dbg !40, !tbaa !26
  %add = add nsw i32 %5, 1, !dbg !41
  %idxprom = sext i32 %add to i64, !dbg !38
  %arrayidx = getelementptr inbounds double, double* %4, i64 %idxprom, !dbg !38
  %6 = load double, double* %arrayidx, align 8, !dbg !42, !tbaa !43
  %add1 = fadd double %6, 1.000000e+00, !dbg !42
  store double %add1, double* %arrayidx, align 8, !dbg !42, !tbaa !43
  br label %for.inc, !dbg !45

if.end:                                           ; preds = %for.body
  %7 = load double*, double** %A.addr, align 8, !dbg !46, !tbaa !19
  %8 = load i32, i32* %i, align 4, !dbg !47, !tbaa !26
  %idxprom2 = sext i32 %8 to i64, !dbg !46
  %arrayidx3 = getelementptr inbounds double, double* %7, i64 %idxprom2, !dbg !46
  %9 = load double, double* %arrayidx3, align 8, !dbg !46, !tbaa !43
  %call4 = call double @boo(double %9), !dbg !48
  %10 = load double*, double** %A.addr, align 8, !dbg !49, !tbaa !19
  %11 = load i32, i32* %i, align 4, !dbg !50, !tbaa !26
  %idxprom5 = sext i32 %11 to i64, !dbg !49
  %arrayidx6 = getelementptr inbounds double, double* %10, i64 %idxprom5, !dbg !49
  store double %call4, double* %arrayidx6, align 8, !dbg !51, !tbaa !43
  %12 = load double*, double** %A.addr, align 8, !dbg !52, !tbaa !19
  %13 = load i32, i32* %i, align 4, !dbg !54, !tbaa !26
  %idxprom7 = sext i32 %13 to i64, !dbg !52
  %arrayidx8 = getelementptr inbounds double, double* %12, i64 %idxprom7, !dbg !52
  %14 = load double, double* %arrayidx8, align 8, !dbg !52, !tbaa !43
  %conv = fptosi double %14 to i32, !dbg !52
  %call9 = call i32 @is_prime(i32 %conv), !dbg !55
  %tobool10 = icmp ne i32 %call9, 0, !dbg !55
  br i1 %tobool10, label %if.then11, label %if.end15, !dbg !56

if.then11:                                        ; preds = %if.end
  %15 = load double*, double** %A.addr, align 8, !dbg !57, !tbaa !19
  %16 = load i32, i32* %i, align 4, !dbg !59, !tbaa !26
  %add12 = add nsw i32 %16, 1, !dbg !60
  %idxprom13 = sext i32 %add12 to i64, !dbg !57
  %arrayidx14 = getelementptr inbounds double, double* %15, i64 %idxprom13, !dbg !57
  %17 = load double, double* %arrayidx14, align 8, !dbg !61, !tbaa !43
  %mul = fmul double %17, 3.000000e+00, !dbg !61
  store double %mul, double* %arrayidx14, align 8, !dbg !61, !tbaa !43
  br label %if.end15, !dbg !62

if.end15:                                         ; preds = %if.then11, %if.end
  br label %for.inc, !dbg !63

for.inc:                                          ; preds = %if.end15, %if.then
  %18 = load i32, i32* %i, align 4, !dbg !64, !tbaa !26
  %inc = add nsw i32 %18, 1, !dbg !64
  store i32 %inc, i32* %i, align 4, !dbg !64, !tbaa !26
  br label %for.cond, !dbg !32, !llvm.loop !65

for.end:                                          ; preds = %for.cond.cleanup
  ret void, !dbg !68
}

; Function Attrs: nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #2

declare dso_local i32 @is_prime(i32) #3

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
!1 = !DIFile(filename: "C:\\Users\\weaut\\Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_20\\main.c", directory: "C:\\Users\\weaut", checksumkind: CSK_MD5, checksum: "03dbcb0a4df7a076245875dfa1cf53ad")
!2 = !{}
!3 = !{i32 2, !"CodeView", i32 1}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 2}
!6 = !{i32 7, !"PIC Level", i32 2}
!7 = !{!"clang version 11.0.0 (https://github.com/llvm/llvm-project.git 81eb1c1fa75c6407713b5657156d8d9149572bfe)"}
!8 = distinct !DISubprogram(name: "far", scope: !9, file: !9, line: 6, type: !10, scopeLine: 6, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition | DISPFlagOptimized, unit: !0, retainedNodes: !14)
!9 = !DIFile(filename: "Documents\\GitHub\\tsar-test-dev\\tests\\analysis\\expr_matcher\\match_20\\main.c", directory: "C:\\Users\\weaut", checksumkind: CSK_MD5, checksum: "03dbcb0a4df7a076245875dfa1cf53ad")
!10 = !DISubroutineType(types: !11)
!11 = !{null, !12}
!12 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !13, size: 64)
!13 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!14 = !{!15, !16}
!15 = !DILocalVariable(name: "A", arg: 1, scope: !8, file: !9, line: 6, type: !12)
!16 = !DILocalVariable(name: "i", scope: !17, file: !9, line: 7, type: !18)
!17 = distinct !DILexicalBlock(scope: !8, file: !9, line: 7, column: 3)
!18 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!19 = !{!20, !20, i64 0}
!20 = !{!"any pointer", !21, i64 0}
!21 = !{!"omnipotent char", !22, i64 0}
!22 = !{!"Simple C/C++ TBAA"}
!23 = !DILocation(line: 6, column: 18, scope: !8)
!24 = !DILocation(line: 7, column: 8, scope: !17)
!25 = !DILocation(line: 7, column: 12, scope: !17)
!26 = !{!27, !27, i64 0}
!27 = !{!"int", !21, i64 0}
!28 = !DILocation(line: 7, column: 19, scope: !29)
!29 = distinct !DILexicalBlock(scope: !17, file: !9, line: 7, column: 3)
!30 = !DILocation(line: 7, column: 21, scope: !29)
!31 = !DILocation(line: 7, column: 3, scope: !17)
!32 = !DILocation(line: 7, column: 3, scope: !29)
!33 = !DILocation(line: 8, column: 18, scope: !34)
!34 = distinct !DILexicalBlock(scope: !35, file: !9, line: 8, column: 9)
!35 = distinct !DILexicalBlock(scope: !29, file: !9, line: 7, column: 35)
!36 = !DILocation(line: 8, column: 9, scope: !34)
!37 = !DILocation(line: 8, column: 9, scope: !35)
!38 = !DILocation(line: 9, column: 7, scope: !39)
!39 = distinct !DILexicalBlock(scope: !34, file: !9, line: 8, column: 22)
!40 = !DILocation(line: 9, column: 9, scope: !39)
!41 = !DILocation(line: 9, column: 11, scope: !39)
!42 = !DILocation(line: 9, column: 16, scope: !39)
!43 = !{!44, !44, i64 0}
!44 = !{!"double", !21, i64 0}
!45 = !DILocation(line: 10, column: 7, scope: !39)
!46 = !DILocation(line: 12, column: 16, scope: !35)
!47 = !DILocation(line: 12, column: 18, scope: !35)
!48 = !DILocation(line: 12, column: 12, scope: !35)
!49 = !DILocation(line: 12, column: 5, scope: !35)
!50 = !DILocation(line: 12, column: 7, scope: !35)
!51 = !DILocation(line: 12, column: 10, scope: !35)
!52 = !DILocation(line: 13, column: 18, scope: !53)
!53 = distinct !DILexicalBlock(scope: !35, file: !9, line: 13, column: 9)
!54 = !DILocation(line: 13, column: 20, scope: !53)
!55 = !DILocation(line: 13, column: 9, scope: !53)
!56 = !DILocation(line: 13, column: 9, scope: !35)
!57 = !DILocation(line: 14, column: 7, scope: !58)
!58 = distinct !DILexicalBlock(scope: !53, file: !9, line: 13, column: 25)
!59 = !DILocation(line: 14, column: 9, scope: !58)
!60 = !DILocation(line: 14, column: 11, scope: !58)
!61 = !DILocation(line: 14, column: 16, scope: !58)
!62 = !DILocation(line: 15, column: 5, scope: !58)
!63 = !DILocation(line: 16, column: 3, scope: !35)
!64 = !DILocation(line: 7, column: 30, scope: !29)
!65 = distinct !{!65, !31, !66, !67}
!66 = !DILocation(line: 16, column: 3, scope: !17)
!67 = !{!"llvm.loop.unroll.disable"}
!68 = !DILocation(line: 17, column: 1, scope: !8)
